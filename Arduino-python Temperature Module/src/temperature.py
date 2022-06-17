import time


def run_temp(bool):
    if type(bool) is str:

        if bool.lower() == 'true':

            file = open("src/Data/data.txt", "r")
            file_read = file.read()
            raw_value = file_read.split("\n")
            temp_raw = raw_value[-2].split(",")
            temp = temp_raw[0]
            humid = temp_raw[1]

            data = {
                'temp': temp,
                'humid': humid
            }

            print('Humidity = ' + data['humid'] + '%')
            print('Temperature = ' + data['temp'] + 'ºC')

            time.sleep(4)
    else:
        return print('Error at calling the function "run_temp", the parameter must be a string.')
