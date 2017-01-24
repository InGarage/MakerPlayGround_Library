import csv
import json
import collections
import sys

if __name__ == '__main__':
    input_filename = 'action.csv'
    output_filename = 'action.json'

    # Temporary variable to store data to be written to the json file
    data = collections.OrderedDict()

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
                    data[row['category']] = category

                # We have found a new action so we create a dict and append to the correct category
                if len(row['id']) != 0:
                    action = collections.OrderedDict([('id', row['id']),
                                                      ('name', row['name']),
                                                      ('short_description', row['short_description']),
                                                      ('description', row['description']),
                                                      ('params', collections.OrderedDict())])
                    category.append(action)

                # If a parameter is found, we append it to the current action. If an argument
                # is found, we append it the the current parameter
                if len(row['param']) != 0:
                    param = collections.OrderedDict([('control', row['param_control']),
                                                     ('default_value', row['param_default_value']),
                                                     ('args', [row['param_arg']]),
                                                     ('regex', row['param_regex']),
                                                     ('description', row['param_description'])])
                    action['params'][row['param']] = param
                elif len(row['param_arg']) != 0:
                    param['args'].append(row['param_arg'])
                
                # Raise error if no valid information is found in any column
                if (len(row['id']) == 0) and (len(row['param']) == 0) and (len(row['param_arg']) == 0):
                    raise csv.Error('No valid data is detected at this line!!!')
        except csv.Error as e:
            # Exit and display error massage if the input CSV file is invalid
            sys.exit('file {}, line {}: {}'.format(input_filename, reader.line_num, e))

    with open(output_filename, 'w') as csvfile:
        json.dump(data, csvfile, indent=2)
