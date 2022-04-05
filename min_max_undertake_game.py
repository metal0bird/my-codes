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
#scores = [3, 5, 2, 9, 12, 5, 23, 23]
treeDepth = int(input())  # taking the depth as input

sarr = list(map(int, input().strip().split()))
#  sarr = np.random.randint(-1, 1, 8)             #this was to test the code with random input values
# print(sarr)
print("The optimal solution is : ")

list_root = [minimax(0, 0, True, sarr, treeDepth)]

# this is to print each line of the tree one by one
print("root->", end=" ")
print(list_root)
#print("min->", end=" ")
print(minList)
#print("max", end=" ")
print(maxList[:-1])
print("leaf", end=" ")
print(sarr)
