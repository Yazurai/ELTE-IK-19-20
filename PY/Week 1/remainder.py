divident = 0.0
inputSuccess = False
while not inputSuccess:
    inputSuccess = True
    try:
        divident = int(input("Please enter a divident:"))
    except ValueError:
        inputSuccess = False
        print('Please enter a valid number!')

divisor = 0.0
inputSuccess = False
while not inputSuccess:
    inputSuccess = True
    try:
        divisor = int(input("Please enter a divisor:"))
    except ValueError:
        inputSuccess = False
        print('Please enter a valid number!')

while divident > divisor:
    divident -= divisor
print("The remainder is " + str(divident))
