import math

def count_bit(n):
    count = 0
    while n:
        count+=1
        n=n & n-1
    return count


n = int(input())
if n&(n-1)==0:
    print(1)
else:
    k = 2*(n - math.pow(2,math.floor(math.log2(n)))) + 1
    print(k)