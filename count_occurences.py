import math
import os
import random
import re
import sys

# Complete the countingSort function below.
def countingSort(arr):
    max_element = max(arr)
    countArr = [0]*(max_element+1)
    for a in arr:
        countArr[a]+=1
    toPrint = []
    for i in range(len(countArr)):
        toPrint += [i]*countArr[i]
    return toPrint
    
n = int(input())
arr = list(map(int, input().rstrip().split()))
result = countingSort(arr)
