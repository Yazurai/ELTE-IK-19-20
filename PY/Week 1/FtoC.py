fahrenheit = 0.0
inputSuccess = False
while not inputSuccess:
    inputSuccess = True
    try:
        fahrenheit = float(input("Please enter the temperature in Fahrenheit!"))
    except ValueError:
        inputSuccess = False
        print('Please enter a valid number!')
celsius = (fahrenheit - 32) * 5 / 9
print(str('%.2f' % fahrenheit) + " Fahrenheit is " + str('%.2f' % celsius) + " Celsius.")