import math
import os
import random
import re
import sys

# Complete the closestNumbers function below.
def closestNumbers(arr):
    arr.sort()
    min_diff = sys.maxsize
    output = []
    for i in range(len(arr)-1):
        if abs(arr[i+1]-arr[i])<min_diff:
            min_diff =  abs(arr[i+1]-arr[i]) 
    for i in range(len(arr)-1):
        if abs(arr[i+1]-arr[i]) == min_diff:
            output.append(arr[i])
            output.append(arr[i+1]) 
    return output     

n = int(input())
arr = list(map(int, input().rstrip().split()))
result = closestNumbers(arr)