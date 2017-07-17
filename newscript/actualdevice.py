import csv
import json
import collections
import sys

def isfloat(value):
    try:
        float(value)
        return True
    except ValueError:
        return False

if __name__ == '__main__':
    input_filename = 'actualdevice.csv'
    output_filename = 'actualdevice.json'
    
    # Temporary variable to store data to be written to the json file
    data = []

    with open(input_filename, newline='') as csvfile:
        reader = csv.DictReader(csvfile)
        obj = None
        device = None
        action = None
        param = None
        constraint = None
        devicevalue = None
        value = None
        constraintvalue = None
        # Add new variable for default action
        #defaultaction = None
        try:
            for row in reader:
                # We have found a new category so we create an array and put it into the dict
                if len(row['brand']) != 0:
                    supportdevices = []
                    supportdevicevalues = []
                    obj = collections.OrderedDict([('brand', row['brand']),
                                                   ('model', row['model']),
                                                   ('url', row['url']),
                                                   ('supportdevice', supportdevices),
                                                   ('supportvalue', supportdevicevalues)])
                    data.append(obj)
                    
                if len(row['supportdevice']) != 0:
                    actions = []
                    device = collections.OrderedDict([('name', row['supportdevice']),
                                                      ('action', actions)])
                    supportdevices.append(device)
               
                if len(row['supportaction']) != 0:
                    params = []         
                    action = collections.OrderedDict([('name', row['supportaction']),
                                                      ('parameter', params)])
                    actions.append(action)

                if len(row['supportactionparam']) != 0:
                    constraints = []
                    param = collections.OrderedDict([('name', row['supportactionparam']),
                                                     ('constraint', constraints)])
                    params.append(param)

                if len(row['constraintunit']) != 0:
                    constraint = collections.OrderedDict([('min', float(row['constraintmin'])),
                                                          ('max', float(row['constraintmax'])),
                                                          ('unit', row['constraintunit'])])
                    constraints.append(constraint)

                if len(row['constraintvalue']) !=0:
                    constraints.append(row['constraintvalue'])

                if len(row['supportdevicevalue']) !=0:
                    values = []
                    devicevalue = collections.OrderedDict([('name', row['supportdevicevalue']),
                                                           ('value', values)])
                    supportdevicevalues.append(devicevalue)

                if len(row['supportvalue']) !=0:
                    constraintvalues = []
                    value = collections.OrderedDict([('name', row['supportvalue']),
                                                     ('constraint', constraintvalues)])
                    values.append(value)

                if len(row['constraintvalueunit']) != 0:
                    constraintvalue = collections.OrderedDict([('min', float(row['constraintvaluemin'])),
                                                          ('max', float(row['constraintvaluemax'])),
                                                          ('unit', row['constraintvalueunit'])])
                    constraintvalues.append(constraintvalue)

                if len(row['constraintvaluevalue']) !=0:
                    constraintvalues.append(row['constraintvaluevalue'])
                    

                # Raise error if no valid information is found in any column
                if ((len(row['brand']) == 0) and (len(row['supportdevice']) == 0) and (len(row['supportaction']) == 0)
                    and (len(row['supportactionparam']) == 0) and (len(row['constraintunit']) == 0) and (len(row['constraintvalue']) == 0)
                    and (len(row['supportdevicevalue']) == 0) and (len(row['supportvalue']) == 0)
                    and (len(row['constraintvalueunit']) == 0) and (len(row['constraintvaluevalue']) == 0)):
                    raise csv.Error('No valid data is detected at this line!!!')
        except csv.Error as e:
            # Exit and display error massage if the input CSV file is invalid
            print(e)
            sys.exit('file {}, line {}: {}'.format(input_filename, reader.line_num, e))

    with open(output_filename, 'w') as csvfile:
        print('success')
        json.dump(data, csvfile, indent=2)
