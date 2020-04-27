import math
import os
import random
import re
import sys

# Complete the pairs function below.
def pairs(k, arr):
    i=0
    j=1
    count = 0
    arr.sort()
    while j<len(arr):
        diff = arr[j] - arr[i]
        if diff == k:
            count+=1
            j+=1
        elif diff>k:
            i+=1
        elif diff<k:
            j+=1
    return count



nk = input().split()
n = int(nk[0])
k = int(nk[1])
arr = list(map(int, input().rstrip().split()))
result = pairs(k, arr)
print(result)