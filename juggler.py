import math
n = int(input())
a=n
print(a)
while a!=1:
    if a%2 == 0:
        b = math.floor(math.sqrt(a))
    else:
        b = math.sqrt(a)
        b = math.floor(b*b*b)
    print(b)
    a=b