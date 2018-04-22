import csv
import json
import collections
import sys

if __name__ == '__main__':
    input_filename = 'genericconnectivitydevice.csv'
    output_filename = 'genericconnectivitydevice.json'

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
                    actionList = []
                    propertyList = []
                    obj = collections.OrderedDict([
                        ('name', row['name']),
                        ('description', row['description']),
                        ('conditionList', conditionList),
                        ('sensibleValueList', sensibleValueList),
                        ('actionList', actionList),
                        ('propertyList', propertyList),
                    ])
                    data.append(obj)

                if len(row['condition_name']) != 0:
                    conditionParameterList = []
                    condition = collections.OrderedDict([('name', row['condition_name']),
                                                      ('functionName', row['condition_functionName']),
                                                      ('parameterList', conditionParameterList)])
                    conditionList.append(condition)

                if len(row['condition_param_name']) != 0:
                    if row['condition_param_type'] == 'DOUBLE' or row['condition_param_type'] == 'INTEGER':
                        param = collections.OrderedDict([
                            ('name', row['condition_param_name']),
                            ('type', row['condition_param_type']),
                            ('control', row['condition_param_actionControl']),
                            ('minNumberValue', float(row['condition_param_minNumberValue'])),
                            ('maxNumberValue', float(row['condition_param_maxNumberValue'])),
                            ('defaultNumberValue', float(row['condition_param_defaultNumberValue'])),
                            ('numberUnit', row['condition_param_numberUnit']),
                        ])
                    elif row['condition_param_type'] == 'ENUM':
                        conditionPossibleEnumValues = [ row['condition_param_possibleEnumValues'] ]
                        param = collections.OrderedDict([
                            ('name', row['condition_param_name']),
                            ('type', row['condition_param_type']),
                            ('control', row['condition_param_actionControl']),
                            ('possibleEnumValues', conditionPossibleEnumValues),
                            ('defaultEnumValue', row['condition_param_defaultEnumValue']),
                        ])
                    conditionParameterList.append(param)
                elif len(row['condition_param_possibleEnumValues']) != 0:
                    conditionPossibleEnumValues.append(row['condition_param_possibleEnumValues'])

                if len(row['sensiblevalue_name']) != 0:
                    sensibleValue = collections.OrderedDict([
                        ('name', row['sensiblevalue_name']),
                        ('type', row['sensiblevalue_type']),
                        ('unit', row['sensiblevalue_unit']),
                        ('minValue', float(row['sensiblevalue_minValue'])),
                        ('maxValue', float(row['sensiblevalue_maxValue'])),
                    ])
                    sensibleValueList.append(sensibleValue)

                if len(row['action_name']) != 0:
                    actionParameterList = []
                    action = collections.OrderedDict([('name', row['action_name']),
                                                      ('functionName', row['action_functionName']),
                                                      ('parameterList', actionParameterList)])
                    actionList.append(action)

                if len(row['action_param_name']) != 0:
                    if row['action_param_type'] == 'DOUBLE':
                        param = collections.OrderedDict([
                            ('name', row['action_param_name']),
                            ('type', row['action_param_type']),
                            ('control', row['action_param_actionControl']),
                            ('minNumberValue', float(row['action_param_minNumberValue'])),
                            ('maxNumberValue', float(row['action_param_maxNumberValue'])),
                            ('defaultNumberValue', float(row['action_param_defaultNumberValue'])),
                            ('numberUnit', row['action_param_numberUnit']),
                        ])
                    elif row['action_param_type'] == 'INTEGER':
                        param = collections.OrderedDict([
                            ('name', row['action_param_name']),
                            ('type', row['action_param_type']),
                            ('control', row['action_param_actionControl']),
                            ('minNumberValue', int(row['action_param_minNumberValue'])),
                            ('maxNumberValue', int(row['action_param_maxNumberValue'])),
                            ('defaultNumberValue', int(row['action_param_defaultNumberValue'])),
                            ('numberUnit', row['action_param_numberUnit']),
                        ])
                    elif row['action_param_type'] == 'ENUM':
                        actionPossibleEnumValues = [ row['action_param_possibleEnumValues'] ]
                        param = collections.OrderedDict([
                            ('name', row['action_param_name']),
                            ('type', row['action_param_type']),
                            ('control', row['action_param_actionControl']),
                            ('possibleEnumValues', actionPossibleEnumValues),
                            ('defaultEnumValue', row['action_param_defaultEnumValue']),
                        ])
                    elif row['action_param_type'] == 'VALUE':
                        actionPossibleEnumValues = [ row['action_param_possibleEnumValues'] ]
                        param = collections.OrderedDict([
                            ('name', row['action_param_name']),
                            ('type', row['action_param_type']),
                            ('control', row['action_param_actionControl']),
                        ])
                    actionParameterList.append(param)
                elif len(row['action_param_possibleEnumValues']) != 0:
                    actionPossibleEnumValues.append(row['condition_param_possibleEnumValues'])

                if len(row['property_name']) != 0:
                    device_property = collections.OrderedDict([
                        ('name', row['property_name']),
                        ('type', row['property_type']),
                    ])
                    propertyList.append(device_property)

                # Raise error if no valid information is found in any column
                if (len(row['condition_name']) == 0
                    and len(row['condition_param_name']) == 0
                    and len(row['condition_param_possibleEnumValues']) == 0 
                    and len(row['sensiblevalue_name']) == 0
                    and len(row['action_name']) == 0
                    and len(row['action_param_name']) == 0
                    and len(row['action_param_possibleEnumValues']) == 0
                    and len(row['property_name']) == 0):
                    raise csv.Error('No valid data is detected at this line!!!')

        except csv.Error as e:
            # Exit and display error massage if the input CSV file is invalid
            print(e)
            sys.exit('file {}, line {}: {}'.format(input_filename, reader.line_num, e))

    with open(output_filename, 'w') as csvfile:
        print('success')
        json.dump(data, csvfile, indent=2)
