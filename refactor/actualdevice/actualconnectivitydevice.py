import csv
import json
import collections
import sys


def isfloat(tempfloat):
    try:
        float(tempfloat)
        return float(tempfloat)
    except ValueError:
        return tempfloat


if __name__ == '__main__':
    input_filename = 'actualconnectivitydevice.csv'
    output_filename = 'actualconnectivitydevice.json'

    # Temporary variable to store data to be written to the json file
    data = []
    with open(input_filename, newline='') as csvfile:
        reader = csv.DictReader(csvfile)
        ports = []
        compatibilities = []
        functions = []
        actions = []
        values = []
        params = []
        constraint = []
        valueconstraint = []
        properties = []
        try:
            for row in reader:
                # We have found a new category so we create an array and put it into the actualdevice
                if len(row['id']) != 0:
                    ports = []
                    compatibilities = []
                    actualdevice = collections.OrderedDict([('id', row['id']),
                                                            ('brand', row['brand']),
                                                            ('model', row['model']),
                                                            ('url', row['url']),
                                                            ('type', row['type']),
                                                            ('formfactor', row['formfactor']),
                                                            ('platform', []),
                                                            ('library', []),
                                                            ('width', isfloat(row['width'])),
                                                            ('height', isfloat(row['height'])),
                                                            ('v', isfloat(row['v'])),
                                                            ('i', isfloat(row['i'])),
                                                            ('w', isfloat(row['w'])),
                                                            ('dependency', row['dependency']),
                                                            ('category', row['category']),
                                                            ('port', ports),
                                                            ('connectivity', []),
                                                            ('compatibility', compatibilities)
                                                            ])
                    data.append(actualdevice)

                if len(row['platform']) != 0:
                    actualdevice['platform'].append(row['platform'])

                if len(row['library']) != 0:
                    actualdevice['library'].append(row['library'])

                if len(row['portname']) != 0:
                    functions = []
                    port = collections.OrderedDict([('name', row['portname']),
                                                    ('type', row['porttype']),
                                                    ('function', functions),
                                                    ('v_min', isfloat(row['v_min'])),
                                                    ('v_max', isfloat(row['v_max'])),
                                                    ('x', isfloat(row['x'])),
                                                    ('y', isfloat(row['y']))])
                    ports.append(port)

                if len(row['functiontype']) != 0:
                    tempfunction = collections.OrderedDict([('type', row['functiontype']),
                                                            ('pintype', row['functionpintype'])])
                    functions.append(tempfunction)

                if len(row['connectivity']) != 0:
                    actualdevice['connectivity'].append(row['connectivity'])

                if len(row['compatibility']) != 0:
                    actions = []
                    values = []
                    compatibility = collections.OrderedDict([('name', row['compatibility']),
                                                             ('action', actions),
                                                             ('value', values),
                                                             ('count', isfloat(row['count']))])
                    compatibilities.append(compatibility)

                if len(row['action']) != 0:
                    params = []
                    action = collections.OrderedDict([('name', row['action']),
                                                      ('parameter', params)])
                    actions.append(action)

                if len(row['param']) != 0:
                    constraint = []
                    if len(row['unit']) != 0:
                        constraint = collections.OrderedDict([('min', isfloat(row['min'])),
                                                              ('max', isfloat(row['max'])),
                                                              ('unit', row['unit'])])
                    param = collections.OrderedDict([('name', row['param']),
                                                     ('constraint', constraint)])
                    params.append(param)

                if len(row['constraint']) != 0:
                    constraint.append(row['constraint'])

                if len(row['value']) != 0:
                    valueconstraint = []
                    if len(row['valueunit']) != 0:
                        valueconstraint = collections.OrderedDict([('min', isfloat(row['valuemin'])),
                                                                   ('max', isfloat(row['valuemax'])),
                                                                   ('unit', row['valueunit'])])
                    value = collections.OrderedDict([('name', row['value']),
                                                     ('constraint', valueconstraint)])
                    values.append(value)

                if len(row['valueconstraint']) != 0:
                    valueconstraint.append(row['valueconstraint'])

                # Raise error if no valid information is found in any column
                if ((len(row['id']) == 0) and (len(row['platform']) == 0)
                    and (len(row['portname']) == 0) and (len(row['functiontype']) == 0)
                    and (len(row['connectivity']) == 0) and (len(row['compatibility']) == 0)
                    and (len(row['action']) == 0) and (len(row['param']) == 0)
                    and (len(row['constraint']) == 0) and (len(row['value']) == 0)
                    and (len(row['valueconstraint']) == 0) and (len(row['dependency']) == 0)):
                    raise csv.Error('No valid data is detected at this line!!!')
        except csv.Error as e:
            # Exit and display error massage if the input CSV file is invalid
            print(e)
            sys.exit('file {}, line {}: {}'.format(input_filename, reader.line_num, e))

    with open(output_filename, 'w') as csvfile:
        print('success')
        json.dump(data, csvfile, indent=2)
