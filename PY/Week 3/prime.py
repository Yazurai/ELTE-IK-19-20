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
isPrime = True
for i in range(2, n/2, 1):
	if n % i == 0:
		isPrime = False
if(isPrime):
	print("The number is a prime.")
else:
	print("The number is not a prime.")
