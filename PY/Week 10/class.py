from collections import Counter

a = list(zip (['a', 'b'], [1,2,3,4]))
print(a)
b = list(map(lambda x: x**2, range(1,11)))
print(b)
cs = "Hello This is a TEXT"
lowerCount = sum(int(c.islower()) for c in cs)
upperCount = sum(int(c.isupper()) for c in cs)
letterCounts = Counter(cs)
print(letterCounts)
print(cs + ": " + str(lowerCount) + ", " + str(upperCount))
ds = [1,2,3,4,5,6,7,8,9,1,3,4,7,8]
counts = Counter(ds)
corrects = list(filter(lambda x: counts.get(x) == 1, ds))
correctCount = len(corrects)
print(ds)
print(str(correctCount))
n = 5
x = 16
es = [1,2,3,4,5,6,7,8,9,10,11,12,13,14]
for i in es
exists = len(list(filter(lambda e: n+e == x, es))) > 0
print(exists)
max=0
fs = [1,2,3,4,1,2,3,1,2,1,2,3,4,5,6,1,2,3,4,1,2,3]

