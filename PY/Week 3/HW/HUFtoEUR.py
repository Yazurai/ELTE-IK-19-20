n = 0.0
inputSuccess = False
while not inputSuccess:
    inputSuccess = True
    try:
        n = int(input("Please enter n:"))
    except ValueError:
        inputSuccess = False
        print('Please enter a valid number!')
for n in range(1, n, 1):
    print(n, "HUF is ", n * 0.00299728261, "EUR.")