n = 0
inputSuccess = False
while not inputSuccess:
    inputSuccess = True
    try:
        n = int(input("Please enter n:"))
    except ValueError:
        inputSuccess = False
        print('Please enter a valid number!')
for i in range(1, n, 1):
	output = ""
	if i % 3 == 0:
		output += "fizz"
	if i % 5 == 0:
		output += "buzz"
	if output == "":
		output = str(i)

	print(output)
