import csv
import json
import collections
import sys
import os

if __name__ == '__main__':
    input_filename = 'actualdevice.csv'
    output_filename = 'actualdevice.json'

    # Temporary variable to store data to be written to the json file
    data = []
    with open(input_filename, newline='') as csvfile:
        reader = csv.DictReader(csvfile)
        try:
            for row in reader:
                # We have found a new category so we create an array and put it into the actualdevice
                if len(row['id']) != 0:
                    hostConnectionsList = []
                    portInstances = {}
                    listGenericDeviceCompatible = []
                    platformLibraries = {}
                    actualdevice = collections.OrderedDict([
                        ('id', row['id']),
                        ('brand', row['brand']),
                        ('model', row['model']),
                        ('url', row['url']),
                        ('type', row['type']),
                        ('formfactor', row['formfactor']),
                        ('width', float(row['width'])),
                        ('height', float(row['height'])),
                        ('hostConnectionsList', hostConnectionsList),
                        ('portInstances', portInstances),
                        ('listGenericDeviceCompatible', listGenericDeviceCompatible),
                        ('platformLibraries', platformLibraries),
                    ])
                    data.append(actualdevice)

                if len(row['porttype']) != 0:
                    port_type = row['porttype']
                    portInstances[port_type] = []
                    # actualdevice['portInstances'] = { port_type : [] }

                if len(row['portinstance']) != 0:
                    pinList = []
                    port = {
                        'name': row['portinstance_name'],
                        'wiring': row['wiring'],
                        'pinList': pinList,
                    }
                    actualdevice['portInstances'][port_type].append(port)

                if len(row['pinname']) != 0:
                    pin = {
                        'name': row['pinname'],
                        'function': row['pinfunction'],
                        'x': float(row['pinx']),
                        'y': float(row['piny']),
                        'adapt_pin': row['adapt_pin'],
                    }
                    pinList.append(pin)

                if len(row['host']) != 0:
                    supportHostList = []
                    connectivityList = []
                    host_connection = {
                        'supportHostList': supportHostList,
                        'connectivityList': connectivityList,
                    }
                    hostConnectionsList.append(host_connection)

                if len(row['support_hosts']) != 0:
                    supportHost = row['support_hosts']
                    supportHostList.append(supportHost)

                if len(row['connectivity_host']) != 0:
                    connectivity = {}
                    connectivityList.append(connectivity)

                if len(row['connectivity_porttype']) != 0:
                    connectivity_port_type = row['connectivity_porttype']
                    connectivity[connectivity_port_type] = []
                
                if len(row['connectivity_portinstance']) != 0:
                    connectivity_port_instance = int(row['connectivity_portinstance'])
                    connectivity[connectivity_port_type].append(connectivity_port_instance)

                if len(row['compatible_generic_device']) != 0:
                    generic_device = row['compatible_generic_device']
                    genericDeviceCompatible = {
                        'generic_device': generic_device,
                    }
                    listGenericDeviceCompatible.append(genericDeviceCompatible)

                if len(row['compatible_genericinput_device_conditions']) != 0:
                    if 'conditionList' not in genericDeviceCompatible:
                        genericDeviceCompatible['conditionList'] = []
                    listConditionParams = []
                    device_condition = {
                        'condition': row['compatible_genericinput_device_conditions'],
                        'params': listConditionParams
                    }
                    genericDeviceCompatible['conditionList'].append(device_condition)

                if len(row['overriding_condition_param_name']) != 0:

                    if row['condition_param_type'] == 'DOUBLE':
                        conditionParam = collections.OrderedDict([
                            ('name', row['overriding_condition_param_name']),
                            ('type', row['condition_param_type']),
                            ('minNumberValue', float(row['condition_minNumberValue'])),
                            ('maxNumberValue', float(row['condition_maxNumberValue'])),
                            ('defaultNumberValue', float(row['condition_defaultNumberValue'])),
                            ('numberUnit', row['condition_numberUnit']),
                        ])
                    elif row['condition_param_type'] == 'INTEGER':
                        conditionParam = collections.OrderedDict([
                            ('name', row['overriding_condition_param_name']),
                            ('type', row['condition_param_type']),
                            ('minNumberValue', int(row['condition_minNumberValue'])),
                            ('maxNumberValue', int(row['condition_maxNumberValue'])),
                            ('defaultNumberValue', int(row['condition_defaultNumberValue'])),
                            ('numberUnit', row['condition_numberUnit']),
                        ])
                    elif row['condition_param_type'] == 'ENUM':
                        possibleConditionEnumValues = []
                        conditionParam = collections.OrderedDict([
                            ('name', row['overriding_condition_param_name']),
                            ('type', row['condition_param_type']),
                            ('possibleEnumValues', possibleConditionEnumValues),
                            ('defaultEnumValue', row['condition_default_enum']),
                        ])
                    listConditionParams.append(conditionParam)

                if len(row['condition_enum_values']) != 0:
                    possibleConditionEnumValues.append(row['condition_enum_values'])

                if len(row['compatible_genericoutput_device_actions']) != 0:
                    if 'action' not in genericDeviceCompatible:
                        genericDeviceCompatible['actionList'] = []
                    listActionParams = []
                    device_action = {
                        'action': row['compatible_genericoutput_device_actions'],
                        'params': listActionParams
                    }
                    genericDeviceCompatible['actionList'].append(device_action)

                if len(row['overriding_action_param_name']) != 0:

                    if row['action_param_type'] == 'DOUBLE':
                        actionParam = collections.OrderedDict([
                            ('name', row['overriding_action_param_name']),
                            ('type', row['action_param_type']),
                            ('minNumberValue', float(row['action_minNumberValue'])),
                            ('maxNumberValue', float(row['action_maxNumberValue'])),
                            ('defaultNumberValue', float(row['action_defaultNumberValue'])),
                            ('numberUnit', row['action_numberUnit']),
                        ])
                    elif row['action_param_type'] == 'INTEGER':
                        actionParam = collections.OrderedDict([
                            ('name', row['overriding_action_param_name']),
                            ('type', row['action_param_type']),
                            ('minNumberValue', int(row['action_minNumberValue'])),
                            ('maxNumberValue', int(row['action_maxNumberValue'])),
                            ('defaultNumberValue', int(row['action_defaultNumberValue'])),
                            ('numberUnit', row['action_numberUnit']),
                        ])
                    elif row['action_param_type'] == 'ENUM':
                        possibleActionEnumValues = []
                        actionParam = collections.OrderedDict([
                            ('name', row['overriding_action_param_name']),
                            ('type', row['action_param_type']),
                            ('possibleEnumValues', possibleActionEnumValues),
                            ('defaultEnumValue', row['action_default_enum']),
                        ])

                    listActionParams.append(actionParam)

                if len(row['action_enum_values']) != 0:
                    possibleActionEnumValues.append(row['action_enum_values'])

                if len(row['overriding_sensible_value']) != 0:
                    if 'sensibleValue' not in genericDeviceCompatible:
                        genericDeviceCompatible['sensibleValueList'] = []
                    sensibleValue = collections.OrderedDict([
                        ('name', row['overriding_sensible_value']),
                        ('type', row['valuetype']),
                        ('minValue', float(row['valuemin'])),
                        ('maxValue', float(row['valuemax'])),
                        ('unit', row['valueunit']),
                    ])
                    genericDeviceCompatible['sensibleValueList'].append(sensibleValue)

                if len(row['platform']) != 0:
                    libraryList = []
                    platform = row['platform']
                    platformLibraries[platform] = libraryList

                if len(row['library']) != 0:
                    libraryList.append(row['library'])

                # # Raise error if no valid information is found in any column
                # if ((len(row['id']) == 0) and (len(row['platform']) == 0)
                #     and (len(row['portname']) == 0) and (len(row['functiontype']) == 0)
                #     and (len(row['connectivity']) == 0) and (len(row['compatibility']) == 0)
                #     and (len(row['action']) == 0) and (len(row['param']) == 0)
                #     and (len(row['constraint']) == 0) and (len(row['value']) == 0)
                #     and (len(row['valueconstraint']) == 0) and (len(row['dependency']) == 0)):
                #     raise csv.Error('No valid data is detected at this line!!!')
        except csv.Error as e:
            # Exit and display error massage if the input CSV file is invalid
            print(e)
            sys.exit('file {}, line {}: {}'.format(input_filename, reader.line_num, e))

    with open(output_filename, 'w') as jsonfile:
        print('success')
        json.dump(data, jsonfile, indent=2)

    for device in data:
        filename = device["id"] + "/device.json"
        os.makedirs(os.path.dirname(filename), exist_ok=True)
        for platform in device['platformLibraries']:
            path = device["id"] + "/" + platform + "/tmp.file"
            os.makedirs(os.path.dirname(path), exist_ok=True)
        with open(filename, 'w') as myFile:
            print('writing', filename)
            json.dump(device, myFile, indent=2)
            print('done')