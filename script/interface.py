import csv
import json
import collections
import sys

if __name__ == '__main__':
    input_filename = 'interface.csv'
    output_filename = 'interface.json'

    # Temporary variable to store data to be written to the json file
    data = []

    with open(input_filename, newline='') as csvfile:
        reader = csv.DictReader(csvfile)
        interface = None
        try:
            for row in reader:
                if len(row['name']) != 0:
                    interface = collections.OrderedDict([('name', row['name']),
                                                         ('lib_name', row['lib_name']),
                                                         ('device_id', row['device_id'])])
                    data.append(interface)
        except csv.Error as e:
            # Exit and display error massage if the input CSV file is invalid
            sys.exit('file {}, line {}: {}'.format(input_filename, reader.line_num, e))

    with open(output_filename, 'w') as csvfile:
        json.dump(data, csvfile, indent=2)
