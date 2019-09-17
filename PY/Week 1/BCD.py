nums = []
for i in range(1, 3, 1):
    inputSuccess = False
    while not inputSuccess:
        inputSuccess = True
        try:
            nums.append(int(input('Enter number ' + str(i) + '/2 (positive decimal): ')))
            if nums[i - 1] < 0:
                inputSuccess = False
        except ValueError:
            inputSuccess = False
            print('Please enter a valid number!')

if nums[0] < nums[1]:
    t = nums[0]
    nums[0] = nums[1]
    nums[1] = t
remainder = nums[0] % nums[1]
while remainder > 0:
    nums[0] = nums[1]
    nums[1] = remainder
    remainder = nums[0] % nums[1]
divisor = nums[1]
print('The highest common divisor is ' + str(divisor))