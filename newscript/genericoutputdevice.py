import csv
import json
import collections
import sys

if __name__ == '__main__':
    input_filename = 'genericoutputdevice.csv'
    output_filename = 'genericoutputdevice.json'
    
    # Temporary variable to store data to be written to the json file
    data = []

    with open(input_filename, newline='') as csvfile:
        reader = csv.DictReader(csvfile)
        obj = None
        action = None
        action_paramname = None
        tempconstraint = None
        # Add new variable for default action
        #defaultaction = None
        try:
            for row in reader:
                # We have found a new category so we create an array and put it into the dict
                if len(row['name']) != 0:
                    outputs = []
                    obj = collections.OrderedDict([('name', row['name']),
                                                   ('action', outputs),
                                                   ('value', [])])
                    data.append(obj)
                    
                # We have found a new action so we create a dict and append to the correct category
                if len(row['action_name']) != 0:
                    action = collections.OrderedDict([('name', row['action_name']),
                                                      ('funcname', row['fn_name']),
                                                      ('type', row['action_type']),
                                                      ('parameter', [])])
                    # Check is default action
                    #if row['defaultaction'] == 'YES':
                    #    obj['defaultAction'] = row['action_name']
                    outputs.append(action)
               
                # If a parameter is found, we append it to the current action. If an argument or a                
                # default value is found, we append it the the current parameter
                if len(row['action_paramname']) != 0:
                    constraints = []

                    if (row['action_paramtype'] == 'DOUBLE' or row['action_paramtype'] == 'INTEGER'):
                        defaultValue = float(row['action_default'])
                        constraints = collections.OrderedDict([('min', float(row['action_constraintmin'])),
                                                               ('max', float(row['action_constraintmax'])),
                                                               ('unit', row['action_constraintunit'])])
                    else:
                        defaultValue = row['action_default']
                        if row['action_paramtype'] == 'ENUM':
                            constraints.append(row['action_constraintvalue'])

                    action_paramname = collections.OrderedDict([('name', row['action_paramname']),
                                                            ('value', defaultValue),
                                                            ('constraint', constraints),
                                                            ('datatype', row['action_paramtype']),
                                                            ('controltype', row['action_control'])])
                    action['parameter'].append(action_paramname)
                elif len(row['action_constraintvalue']) != 0:
                    constraints.append(row['action_constraintvalue'])
                    
                # Raise error if no valid information is found in any column
                if ((len(row['action_name']) == 0) and (len(row['action_paramname']) == 0) 
                    and (len(row['action_constraintvalue']) == 0)):
                    raise csv.Error('No valid data is detected at this line!!!')
        except csv.Error as e:
            # Exit and display error massage if the input CSV file is invalid
            print(e)
            sys.exit('file {}, line {}: {}'.format(input_filename, reader.line_num, e))

    with open(output_filename, 'w') as csvfile:
        print('success')
        json.dump(data, csvfile, indent=2)
