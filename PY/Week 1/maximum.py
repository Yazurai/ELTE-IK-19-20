nums = []
for i in range(1, 4, 1):
    inputSuccess = False
    while not inputSuccess:
        inputSuccess = True
        try:
            nums.append(float(input('Enter number ' + str(i) + '/3: ')))
        except ValueError:
            inputSuccess = False
            print('Please enter a single number!')

maxNum = nums[0]
for i in nums:
    if maxNum < i:
        maxNum = i
print('The maximum of the 3 is ' + str(maxNum))
