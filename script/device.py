import csv
import json
import collections
import sys

if __name__ == '__main__':
    input_filename = 'device.csv'
    output_filename = 'device.json'

    # Temporary variable to store data to be written to the json file
    data = []

    with open(input_filename, newline='') as csvfile:
        reader = csv.DictReader(csvfile)
        device = None
        compatibility = None
        properties = None
        try:
            for row in reader:
                # We have found a new trigger so we create a dict and append to the correct category
                if len(row['id']) != 0:
                    device = collections.OrderedDict([('id', row['id']),
                                                      ('lib_name', row['lib_name']),
                                                      ('compatibility', {}),
                                                      ('brand', row['brand']),
                                                      ('model', row['model']),
                                                      ('ic', row['ic']),
                                                      ('price', row['price']),
                                                      ('detail', row['detail']),
                                                      ('image', row['image']),
                                                      ('connect', [row['connect']]),
                                                      ('min_volt', row['min_volt']),
                                                      ('max_volt', row['max_volt']),
                                                      ('dependency', []),
                                                      ('datasheet', row['datasheet']),
                                                      ('link', row['link'])])
                    data.append(device)

                if len(row['type_fn']) != 0:
                    compatibility = {}
                    device['compatibility'][row['type_fn']] = compatibility

                if len(row['id_fn']) != 0:
                    compatibility[row['id_fn']] = row['fn_name']

                if len(row['depend_type']) != 0:
                    properties = collections.OrderedDict([('type', row['depend_type']),
                    								      ('min', row['depend_min']),
                    								      ('max', row['depend_max']),
                    								      ('unit', row['depend_unit'])]) 
               	    device['dependency'].append(properties)
        except csv.Error as e:
            # Exit and display error massage if the input CSV file is invalid
            sys.exit('file {}, line {}: {}'.format(input_filename, reader.line_num, e))

    with open(output_filename, 'w') as csvfile:
        json.dump(data, csvfile, indent=2)
