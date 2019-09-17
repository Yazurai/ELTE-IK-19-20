a, b, n = 1, 1, 0
inputSuccess = False
while not inputSuccess:
    inputSuccess = True
    try:
        n = int(input("Please enter n:"))
    except ValueError:
        inputSuccess = False
        print('Please enter a valid number!')
while b < n:
    c = a + b
    a = b
    b = c
if(b == n):
    print(str(n) + " is a Fibonacci number.")
else:
    print(str(n) + " is not a Fibonacci number.")

