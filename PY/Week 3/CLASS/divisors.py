n = 0
inputSuccess = False
while not inputSuccess:
    inputSuccess = True
    try:
        n = int(input("Please enter n:"))
    except ValueError:
        inputSuccess = False
        print('Please enter a valid number!')
    if n < 1:
        inputSuccess = False

for i in range(1, n + 1, 1):
    if n % i == 0:
        print(i)

