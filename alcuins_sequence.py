import math

nn=int(input())

for n in range(nn):
    res = (round((n * n) / 12) - math.floor(n / 4) * math.floor((n + 2) / 4))
    print(res,end=" ")