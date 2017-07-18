import csv
import json
import collections
import sys


def isfloat(tempfloat):
    try:
        float(tempfloat)
        return float(tempfloat)
    except ValueError:
        return tempfloat


if __name__ == '__main__':
    input_filename = 'genericinputdevice.csv'
    output_filename = 'genericinputdevice.json'

    # Temporary variable to store data to be written to the json file
    data = []
    with open(input_filename, newline='') as csvfile:
        reader = csv.DictReader(csvfile)
        inputs = []
        values = []
        constraints = []
        valueconstraints = []
        try:
            for row in reader:
                # We have found a new category so we create an array and put it into the obj
                if len(row['name']) != 0:
                    inputs = []
                    values = []
                    obj = collections.OrderedDict([('name', row['name']),
                                                   ('action', inputs),
                                                   ('value', values)])
                    data.append(obj)

                if len(row['action_name']) != 0:
                    action = collections.OrderedDict([('name', row['action_name']),
                                                      ('funcname', row['fn_name']),
                                                      ('type', row['action_type']),
                                                      ('parameter', [])])
                    inputs.append(action)

                if len(row['action_paramname']) != 0:
                    constraints = []
                    if row['action_paramtype'] == 'DOUBLE' or row['action_paramtype'] == 'INTEGER':
                        defaultValue = isfloat(row['action_default'])
                        constraints = collections.OrderedDict([('min', isfloat(row['action_constraintmin'])),
                                                               ('max', isfloat(row['action_constraintmax'])),
                                                               ('unit', row['action_constraintunit'])])
                    elif row['action_paramtype'] == 'ENUM':
                        defaultValue = row['action_default']
                        constraints.append(row['action_constraintvalue'])
                    action_paramname = collections.OrderedDict([('name', row['action_paramname']),
                                                                ('value', defaultValue),
                                                                ('constraint', constraints),
                                                                ('datatype', row['action_paramtype']),
                                                                ('controltype', row['action_control'])])
                    action['parameter'].append(action_paramname)
                elif len(row['action_constraintvalue']) != 0:
                    constraints.append(row['action_constraintvalue'])

                if len(row['value_name']) != 0:
                    valueconstraints = []
                    if row['value_datatype'] == 'DOUBLE' or row['value_datatype'] == 'INTEGER':
                        valueconstraints = collections.OrderedDict([('min', isfloat(row['value_constraintmin'])),
                                                                    ('max', isfloat(row['value_constraintmax'])),
                                                                    ('unit', row['value_constraintunit'])])
                    elif row['value_datatype'] == 'ENUM':
                        valueconstraints.append(row['value_constraintvalue'])
                    value = collections.OrderedDict([('name', row['value_name']),
                                                     ('dataType', row['value_datatype']),
                                                     ('constraint', valueconstraints)])
                    values.append(value)
                elif len(row['value_constraintvalue']) != 0:
                    valueconstraints.append(row['value_constraintvalue'])

                # Raise error if no valid information is found in any column
                if ((len(row['action_name']) == 0) and (len(row['action_paramname']) == 0)
                    and (len(row['action_constraintunit']) == 0) and (len(row['action_constraintvalue']) == 0)
                    and (len(row['value_name']) == 0) and (len(row['value_constraintunit']) == 0)
                    and (len(row['value_constraintvalue']) == 0)):
                    raise csv.Error('No valid data is detected at this line!!!')
        except csv.Error as e:
            # Exit and display error massage if the input CSV file is invalid
            print(e)
            sys.exit('file {}, line {}: {}'.format(input_filename, reader.line_num, e))

    with open(output_filename, 'w') as csvfile:
        print('success')
        json.dump(data, csvfile, indent=2)