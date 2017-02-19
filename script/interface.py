import csv
import json
import collections
import sys

if __name__ == '__main__':
    input_filename = 'interface.csv'
    output_filename = 'interface.json'

    # Temporary variable to store data to be written to the json file
    data = {}

    with open(input_filename, newline='') as csvfile:
        reader = csv.DictReader(csvfile)
        group = None
        try:
            for row in reader:
                # when a new group is found, we create a new group of interface
                if len(row['name']) != 0:
                    group = []
                    group.append(collections.OrderedDict([('lib_name', row['lib_name']),
                                                          ('lib_path', row['lib_path']),
                                                          ('device_id', row['device_id'])]))
                    data[row['name']] = group

                # when a new lib in the current group is found, we append the new lib to the group
                elif len(row['lib_name']) != 0:
                    group.append(collections.OrderedDict([('lib_name', row['lib_name']),
                                                          ('lib_path', row['lib_path']),
                                                          ('device_id', row['device_id'])]))
                else:
                    raise csv.Error('No valid data is detected at this line!!!')

        except csv.Error as e:
            # Exit and display error massage if the input CSV file is invalid
            sys.exit('file {}, line {}: {}'.format(input_filename, reader.line_num, e))

    with open(output_filename, 'w') as csvfile:
        json.dump(data, csvfile, sort_keys=True, indent=2)
