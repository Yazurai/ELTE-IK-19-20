import math;

def powerSet(lst):
    powerSetList = []
    for i in range(0, (int)(math.pow(2, len(lst))), 1):
        newSubList = []
        for j in range(0, len(lst), 1):
            if((i & (1 << j)) > 0):
                newSubList.append(lst[j])
        powerSetList.append(newSubList)
    return powerSetList

set = ['a', 'b', 'c'];
powerSetList = powerSet(set)
for i in range(0, len(powerSetList), 1):
    for j in range(0, len(powerSetList[i]), 1):
        print(powerSetList[i][j], end = "")
    print("")