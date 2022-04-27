def minmax(state, depth, flag):  # samuel is max,rama is min
    if (depth == 0):
        return tree[state]
    if flag == True:
        maxval = -100
        for j in range(2*state+1, 2*state+3):
            value = minmax(j, depth-1, False)
            maxval = max(maxval, value)
        tree[state] = maxval
        return maxval
    else:
        minval = 100
        for j in range(2*state+1, 2*state+3):
            value = minmax(j, depth-1, True)
            minval = min(minval, value)
        tree[state] = minval
        return minval


def display(state, depth, flag):
    if depth != 0:
        if flag == True:
            if tree[2*state+1] >= tree[2*state+2]:
                print("samuel moves left = ", tree[2*state+1])
                display(2*state+1, depth-1, False)
            else:
                print("samuel moves right = ", tree[2*state+2])
                display(2*state+2, depth-1, False)
        else:
            if tree[2*state+1] <= tree[2*state+2]:
                print("rama moves left = ", tree[2*state+1])
                display(2*state+1, depth-1, True)
            else:
                print("rama moves right = ", tree[2*state+2])
                display(2*state+2, depth-1, True)


d = int(input("enter depth: "))
n = (2**(d+1))-1
n2 = (2**d)-1
tree = [0]*(n)
for i in range(n2, n):
    print("enter value of leaf node", i+1, ": ", end='')
    tree[i] = int(input())

val = minmax(0, d, True)
print("\nthe final tree is: ", end='')
print(tree)

print("\nthe best moves are:")
display(0, d, True)
