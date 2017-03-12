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
        try:
            for row in reader:
                # We have found a new trigger so we create a dict and append to the correct category
                if len(row['id']) != 0:
                    device = collections.OrderedDict([('id', row['id']),
                                                      ('name', row['name']),
                                                      ('variant', []),
                                                      ('gpio', []),
                                                      ('pwm', []),
                                                      ('analog', []),
                                                      ('i2c', []),
                                                      ('spi', []),
                                                      ('uart', []),])
                    data.append(device)

                if len(row['variant']) != 0:
                    device['variant'].append(collections.OrderedDict([('name', row['variant']),
                                                                      ('image', row['image'])]))
                if len(row['gpio']) != 0:
                    device['gpio'].append(row['gpio'])
                if len(row['pwm']) != 0:
                    device['pwm'].append(row['pwm'])
                if len(row['analog']) != 0:
                    device['analog'].append(row['analog'])
                if len(row['i2c']) != 0:
                    device['i2c'].append(row['i2c'])
                if len(row['spi']) != 0:
                    device['spi'].append(row['spi'])
                if len(row['uart']) != 0:
                    device['uart'].append(row['uart'])
        except csv.Error as e:
            # Exit and display error massage if the input CSV file is invalid
            sys.exit('file {}, line {}: {}'.format(input_filename, reader.line_num, e))

    with open(output_filename, 'w') as csvfile:
        json.dump(data, csvfile, indent=2)
