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
        try:
            for row in reader:
                # We have found a new trigger so we create a dict and append to the correct category
                if len(row['id']) != 0:
                    device = collections.OrderedDict([('id', row['id']),
                                                      ('mfr', row['mfr']),
                                                      ('mfr_part_no', row['mfr_part_no']),
                                                      ('description', row['description']),
                                                      ('ic', row['ic']),
                                                      ('price', row['price']),
                                                      ('connectivity', row['connectivity']),
                                                      ('vcc_min', row['vcc_min']),
                                                      ('vcc_max', row['vcc_max']),
                                                      ('vccio_min', row['vccio_min']),
                                                      ('vccio_max', row['vccio_max']),
                                                      ('image', row['image']),
                                                      ('link', row['link']),
                                                      ('sub_device', []),
                                                      ('compatibility', [])])
                    data.append(device)

                if len(row['sub_device']) != 0:
                    conflict = []
                    device['sub_device'].append(collections.OrderedDict([('name', row['sub_device']),
                                                                         ('conflict', conflict)]))
                if len(row['sub_device_conflict']) != 0:
                    conflict.append(row['sub_device_conflict'])

                if len(row['type']) != 0:
                    fn = []
                    device['compatibility'].append(collections.OrderedDict([('type', row['type']),
                                                                            ('fn', fn)]))
                if len(row['compatible_fn']) != 0:
                    fn.append(row['compatible_fn'])
        except csv.Error as e:
            # Exit and display error massage if the input CSV file is invalid
            sys.exit('file {}, line {}: {}'.format(input_filename, reader.line_num, e))

    with open(output_filename, 'w') as csvfile:
        json.dump(data, csvfile, indent=2)
