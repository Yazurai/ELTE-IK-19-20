def fibonacci(n):
	fibList = [1,1]
	for i in range(2, n, 1):
		fibList.append(fibList[i-2] + fibList[i-1])
	return fibList
