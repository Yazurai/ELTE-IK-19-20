def getHead(lst, n):
	headList = []
	for i in range(0, n, 1):
		headList.append(lst[i])
	return headList
	
def getTail(lst, n):
	tailList = []
	for i in range(length(lst) - 1 - n, length(lst) - 1, 1):
		tailList.append(lst[i])
	return tailList

exampleList = [1,2,3,4,5,6,7,8,9,10]
n1 = 3
n2 = 5
hList = getHead(exampleList, n1)
tList = getHead(exampleList, n2)
for elem in hList:
	print(str(elem))
for elem in tList:
	print(str(elem))
