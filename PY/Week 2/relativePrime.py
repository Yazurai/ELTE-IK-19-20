a, b = 0.0, 0.0
inputSuccess = False
while not inputSuccess:
    inputSuccess = True
    try:
        a, b = list(map(int, input('Enter two numbers: ').split()))
    except ValueError:
        inputSuccess = False
        print('Enter two valid numbers!')
if a < b:
    t = a
    a = b
    b = t
remainder = a % b
while remainder > 0:
    a = b
    b = remainder
    remainder = a % b
divisor = b
if divisor == 1:
    print("The numbers are relative primes")
else:
    print("The numbers are not relative primes")
