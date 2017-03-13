import csv
import json
import collections
import sys

if __name__ == '__main__':
    input_filename = 'mcu.csv'
    output_filename = 'mcu.json'

    # Temporary variable to store data to be written to the json file
    data = []

    with open(input_filename, newline='') as csvfile:
        reader = csv.DictReader(csvfile)
        device = None
        pin = None
        display = None
        try:
            for row in reader:
                # We have found a new trigger so we create a dict and append to the correct category
                if len(row['id']) != 0:
                    display = collections.OrderedDict()
                    pin = collections.OrderedDict([('gpio', []),
                                                   ('pwm', []),
                                                   ('analog', []),
                                                   ('i2c', []),
                                                   ('spi', []),
                                                   ('uart', [])])
                    device = collections.OrderedDict([('id', row['id']),
                                                      ('name', row['name']),
                                                      ('variant', []),
                                                      ('pin', pin),
                                                      ('display', display)])
                    data.append(device)

                if len(row['variant']) != 0:
                    device['variant'].append(collections.OrderedDict([('name', row['variant']),
                                                                      ('image', row['image'])]))
                if len(row['gpio']) != 0:
                    pin['gpio'].append(row['gpio'])
                if len(row['pwm']) != 0:
                    pin['pwm'].append(row['pwm'])
                if len(row['analog']) != 0:
                    pin['analog'].append(row['analog'])
                if len(row['i2c']) != 0:
                    pin['i2c'].append(row['i2c'])
                if len(row['spi']) != 0:
                    pin['spi'].append(row['spi'])
                if len(row['uart']) != 0:
                    pin['uart'].append(row['uart'])

                if len(row['display_type']) != 0:
                    display['type'] = row['display_type']
                    display['width'] = row['width']
                    display['height'] = row['height']
                    display['pin'] = []
                
                if len(row['pin_name']) != 0:
                    display['pin'].append(collections.OrderedDict([('name', row['pin_name']),
                                                                   ('x', row['location_x']),
                                                                   ('y', row['location_y'])]))
        except csv.Error as e:
            # Exit and display error massage if the input CSV file is invalid
            sys.exit('file {}, line {}: {}'.format(input_filename, reader.line_num, e))

    with open(output_filename, 'w') as csvfile:
        json.dump(data, csvfile, indent=2)
