import csv
import json
import collections
import sys

if __name__ == '__main__':
    if len(sys.argv) != 3:
        print ('Usage: python3 device.py device.csv device.json')
        sys.exit(1)

    input_filename = sys.argv[1]
    output_filename = sys.argv[2]

    # Temporary variable to store data to be written to the json file
    data = []

    with open(input_filename, newline='') as csvfile:
        reader = csv.DictReader(csvfile)
        device = None
        display = None
        try:
            for row in reader:
                # We have found a new trigger so we create a dict and append to the correct category
                if len(row['id']) != 0:
                    display = collections.OrderedDict()
                    device = collections.OrderedDict([('id', row['id']),
                                                      ('mfr', row['mfr']),
                                                      ('mfr_part_no', row['mfr_part_no']),
                                                      ('description', row['description']),
                                                      ('ic', row['ic']),
                                                      ('price', row['price']),
                                                      ('vcc_min', row['vcc_min']),
                                                      ('vcc_max', row['vcc_max']),
                                                      ('vccio_min', row['vccio_min']),
                                                      ('vccio_max', row['vccio_max']),
                                                      ('image', row['image']),
                                                      ('link', row['link']),
                                                      ('sub_device', []),
                                                      ('compatibility', []),
                                                      ('display', display)])
                    data.append(device)

                if len(row['display_type']) != 0:
                    display['type'] = row['display_type']
                    display['width'] = row['width']
                    display['height'] = row['height']
                    display['pin'] = []
                
                if len(row['pin_name']) != 0:
                    display['pin'].append(collections.OrderedDict([('name', row['pin_name']),
                                                                   ('x', row['location_x']),
                                                                   ('y', row['location_y']),
                                                                   ('connection', row['connect_to'])]))

                if len(row['sub_device']) != 0:
                    conflict = []
                    device['sub_device'].append(collections.OrderedDict([('name', row['sub_device']),
                                                                         ('conflict', conflict)]))
                if len(row['sub_device_conflict']) != 0:
                    conflict.append(row['sub_device_conflict'])

                if len(row['connection']) != 0:
                    device_type = []
                    device['compatibility'].append(collections.OrderedDict([('connection', row['connection']),
                                                                            ('optional_connection', row['optional_connection']),
                                                                            ('type', device_type)]))
                if len(row['type']) != 0:
                    fn = []
                    device_type.append(collections.OrderedDict([('name', row['type']),
                                                                ('fn', fn)]))
                if len(row['compatible_fn']) != 0:
                    fn.append(row['compatible_fn'])
        except csv.Error as e:
            # Exit and display error massage if the input CSV file is invalid
            sys.exit('file {}, line {}: {}'.format(input_filename, reader.line_num, e))

    with open(output_filename, 'w') as csvfile:
        json.dump(data, csvfile, indent=2)
