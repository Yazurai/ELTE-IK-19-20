num = 0.0
inputSuccess = False
while not inputSuccess:
    inputSuccess = True
    try:
        num = float(input("Please enter a number:"))
    except ValueError:
        inputSuccess = False
        print('Please enter a valid number!')

sign = 0
if num < 0:
    sign = -1
else:
    if num > 0:
        sign = 1

print ('The sign of the number is ' + str(sign))