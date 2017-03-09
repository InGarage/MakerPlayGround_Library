import csv
import json
import collections
import sys

if __name__ == '__main__':
    input_filename = 'trigger.csv'
    output_filename = 'trigger.json'

    # Temporary variable to store data to be written to the json file
    data = []

    with open(input_filename, newline='') as csvfile:
        reader = csv.DictReader(csvfile)
        category = None
        action = None
        param = None
        try:
            for row in reader:
                # We have found a new category so we create an array and put it into the dict
                if len(row['category']) != 0:
                    category = []
                    data.append(collections.OrderedDict([('name', row['category']),
                                                         ('children', category)]))

                # We have found a new trigger so we create a dict and append to the correct category
                if len(row['id']) != 0:
                    compatibility = collections.OrderedDict([('interface', row['compatible_interface']),
                                                            ('fn_name', row['fn_name'])])
                    action = collections.OrderedDict([('id', row['id']),
                                                      ('name', row['name']),
                                                      ('short_description', row['short_description']),
                                                      #('description', row['description']),
                                                      ('display_text', row['display_text']),
                                                      ('display_text_param', []),
                                                      ('params', []),
                                                      ('compatibility', compatibility)])
                    category.append(action)

                if len(row['display_text_param']) != 0:
                    action['display_text_param'].append(row['display_text_param'])

                # If a parameter is found, we append it to the current trigger. If an argument or a                
                # default value is found, we append it the the current parameter
                if len(row['param']) != 0:
                    param = collections.OrderedDict([('name', row['param']),
                                                     ('control', row['param_control']),
                                                     ('default_value', [row['param_default_value']]),
                                                     ('args', [row['param_arg']]),
                                                     ('regex', row['param_regex'])])
                    action['params'].append(param)
                else:
                    if len(row['param_default_value']) != 0:
                        param['default_value'].append(row['param_default_value'])
                    if len(row['param_arg']) != 0:
                        param['args'].append(row['param_arg'])

                # Raise error if no valid information is found in any column
                if (len(row['id']) == 0) and (len(row['param']) == 0) and (len(row['param_default_value']) == 0) and (len(row['param_arg']) == 0):
                    raise csv.Error('No valid data is detected at this line!!!')
        except csv.Error as e:
            # Exit and display error massage if the input CSV file is invalid
            sys.exit('file {}, line {}: {}'.format(input_filename, reader.line_num, e))

    with open(output_filename, 'w') as csvfile:
        json.dump(data, csvfile, indent=2)
