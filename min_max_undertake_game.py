import math
import numpy as np
maxList = []
minList = []


def minimax(curDepth, nodeIndex,
            maxTurn, scores,
            targetDepth):
    # base case : targetDepth reached
    if (curDepth == targetDepth):
        return scores[nodeIndex]
    if (maxTurn):
        a = max(minimax(curDepth + 1, nodeIndex * 2,
                        False, scores, targetDepth),
                minimax(curDepth + 1, nodeIndex * 2 + 1,
                        False, scores, targetDepth))
        maxList.append(a)
        return a
    else:
        b = min(minimax(curDepth + 1, nodeIndex * 2,
                        True, scores, targetDepth),
                minimax(curDepth + 1, nodeIndex * 2 + 1,
                        True, scores, targetDepth))
        minList.append(b)
        return b


# Driver code

treeDepth = int(input())
d = int(input())
score = list(range(pow(2, (treeDepth-1)+1)))
arr = [0, 1, 2, 3, 14, 15, 26, 7, 8, 9, 10, 11, 12, 13, 14]
if(d % 2 == 0):
    print("Krishna is playing")
else:
    print("Khan player is playing")
start = 0
for x in range(d):
    start = start+pow(2, x)

end = 2*start+1
print(arr[start: end])
