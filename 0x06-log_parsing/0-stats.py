#!/usr/bin/python3
""" Log parsing """


import sys


counter = 0
total_size = 0
codes = {"200": 0,
         "301": 0,
         "400": 0,
         "401": 0,
         "403": 0,
         "404": 0,
         "405": 0,
         "500": 0}

try:
    for l in sys.stdin:
        data = l.split()
        data = data[::-1]
        if len(data) > 2:
            counter += 1
            if counter <= 10:
                total_size += int(data[0])
                code = data[1]
            if code in codes.keys():
                codes[code] += 1
            if counter == 10:
                print('File total_size: {}'.format(total_size))
                for sc, v in sorted(codes.items()):
                    if v != 0:
                        print('{}: {}'.format(sc, v))
                counter = 0

finally:
    print('File total_size: {}'.format(total_size))
    for sc, v in sorted(codes.items()):
        if v != 0:
            print('{}: {}'.format(sc, v))
