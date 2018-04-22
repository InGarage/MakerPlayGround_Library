import csv
import json
import collections
import sys

if __name__ == '__main__':
    input_filename = 'genericinputdevice.csv'
    output_filename = 'genericinputdevice.json'

    # Temporary variable to store data to be written to the json file
    data = []
    with open(input_filename, newline='') as csvfile:
        reader = csv.DictReader(csvfile)
        conditionList = []
        sensibleValueList = []
        try:
            for row in reader:
                # We have found a new category so we create an array and put it into the obj
                if len(row['name']) != 0:
                    conditionList = []
                    sensibleValueList = []
                    obj = collections.OrderedDict([
                        ('name', row['name']),
                        ('description', row['description']),
                        ('conditionList', conditionList),
                        ('sensibleValueList', sensibleValueList)
                    ])
                    data.append(obj)

                if len(row['condition_name']) != 0:
                    parameterList = []
                    condition = collections.OrderedDict([('name', row['condition_name']),
                                                      ('functionName', row['condition_functionName']),
                                                      ('parameterList', parameterList)])
                    conditionList.append(condition)

                if len(row['param_name']) != 0:
                    if row['param_type'] == 'DOUBLE':
                        param = collections.OrderedDict([
                            ('name', row['param_name']),
                            ('type', row['param_type']),
                            ('control', row['param_actionControl']),
                            ('minNumberValue', float(row['param_minNumberValue'])),
                            ('maxNumberValue', float(row['param_maxNumberValue'])),
                            ('defaultNumberValue', float(row['param_defaultNumberValue'])),
                            ('numberUnit', row['param_numberUnit']),
                        ])
                    elif row['param_type'] == 'INTEGER':
                        param = collections.OrderedDict([
                            ('name', row['param_name']),
                            ('type', row['param_type']),
                            ('control', row['param_actionControl']),
                            ('minNumberValue', int(row['param_minNumberValue'])),
                            ('maxNumberValue', int(row['param_maxNumberValue'])),
                            ('defaultNumberValue', int(row['param_defaultNumberValue'])),
                            ('numberUnit', row['param_numberUnit']),
                        ])
                    elif row['param_type'] == 'ENUM':
                        possibleEnumValues = [ row['param_possibleEnumValues'] ]
                        param = collections.OrderedDict([
                            ('name', row['param_name']),
                            ('type', row['param_type']),
                            ('control', row['param_actionControl']),
                            ('possibleEnumValues', possibleEnumValues),
                            ('defaultEnumValue', row['param_defaultEnumValue']),
                        ])
                    parameterList.append(param)
                elif len(row['param_possibleEnumValues']) != 0:
                    possibleEnumValues.append(row['param_possibleEnumValues'])

                if len(row['sensiblevalue_name']) != 0:
                    sensibleValue = collections.OrderedDict([
                        ('name', row['sensiblevalue_name']),
                        ('type', row['sensiblevalue_type']),
                        ('unit', row['sensiblevalue_unit']),
                        ('minValue', float(row['sensiblevalue_minValue'])),
                        ('maxValue', float(row['sensiblevalue_maxValue'])),
                    ])
                    sensibleValueList.append(sensibleValue)

                # Raise error if no valid information is found in any column
                if (len(row['condition_name']) == 0
                    and len(row['param_possibleEnumValues']) == 0 
                    and len(row['sensiblevalue_name']) == 0):
                    raise csv.Error('No valid data is detected at this line!!!')

        except csv.Error as e:
            # Exit and display error massage if the input CSV file is invalid
            print(e)
            sys.exit('file {}, line {}: {}'.format(input_filename, reader.line_num, e))

    with open(output_filename, 'w') as csvfile:
        print('success')
        json.dump(data, csvfile, indent=2)
