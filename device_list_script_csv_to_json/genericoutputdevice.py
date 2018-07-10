import csv
import json
import collections
import sys


if __name__ == '__main__':
    input_filename = '../device_list_csv/genericoutputdevice.csv'
    output_filename = '../device_list_generated_json/genericoutputdevice.json'

    # Temporary variable to store data to be written to the json file
    data = []
    with open(input_filename, newline='') as csvfile:
        reader = csv.DictReader(csvfile)
        outputs = []
        constraints = []
        properties = []
        try:
            for row in reader:
                # We have found a new category so we create an array and put it into the obj
                if len(row['name']) != 0:
                    outputs = []
                    obj = collections.OrderedDict([('name', row['name']),
                                                   ('description', row['description']),
                                                   ('action', outputs),
                                                   ('condition', []),
                                                   ('value', []),
                                                   ('property', properties)])
                    data.append(obj)

                if len(row['action_name']) != 0:
                    action = collections.OrderedDict([('name', row['action_name']),
                                                      ('funcname', row['fn_name']),
                                                      ('type', row['action_type']),
                                                      ('parameter', [])])
                    outputs.append(action)

                if len(row['action_paramname']) != 0:
                    constraints = []
                    if row['action_paramtype'] == 'DOUBLE' or row['action_paramtype'] == 'INTEGER':
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

                if len(row['propertyname']) != 0:
                    properties.append(collections.OrderedDict([('name', row['propertyname']),
                                                               ('type', row['propertytype'])]))

                # Raise error if no valid information is found in any column
                if ((len(row['action_name']) == 0) and (len(row['action_paramname']) == 0)
                    and (len(row['action_constraintvalue']) == 0)
                    and (len(row['propertyname']) == 0)):
                    raise csv.Error('No valid data is detected at this line!!!')
        except csv.Error as e:
            # Exit and display error massage if the input CSV file is invalid
            print(e)
            sys.exit('file {}, line {}: {}'.format(input_filename, reader.line_num, e))

    with open(output_filename, 'w') as csvfile:
        print('success')
        json.dump(data, csvfile, indent=2)
