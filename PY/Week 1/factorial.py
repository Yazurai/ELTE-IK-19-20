n = 0
inputSuccess = False
while not inputSuccess:
    inputSuccess = True
    try:
        n = int(input("Please enter n:"))
    except ValueError:
        inputSuccess = False
        print('Please enter a valid number!')

result = 1
for i in range(1, n + 1, 1):
    result *= i
print('The result is ' + str(result))