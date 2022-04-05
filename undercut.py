import random


list1 = [1, 2, 3, 4, 5]
sum_a = 0
sum_b = 0
print("A", end="\t")
print("B", end="\t")
print("Total points of A", end="\t")
print("Total points of B")

while(sum_a < 100 and sum_b < 100):
    a = random.choice(list1)
    b = random.choice(list1)
    print(a, end="\t")
    print(b, end="\t\t")
    if((a-1) == b):
        sum_b = sum_b+b+a
    elif((b-1) == a):
        sum_a = sum_a+a+b
    else:
        sum_a = sum_a+a
        sum_b = sum_b+b
    print(sum_a, end="\t\t\t")
    print(sum_b)
print()
if(sum_a > sum_b):
    print("A won")
else:
    print("B won")
