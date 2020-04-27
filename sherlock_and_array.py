import math
import os
import random
import re
import sys

# Complete the balancedSums function below.
def balancedSums(arr):
    prefix_arr = [0]*(len(arr))
    prefix_arr[0]=arr[0]
    flag = False
    for i in range(1,len(arr)):
        prefix_arr[i] = prefix_arr[i-1]+arr[i]
    
    for i in range(1,len(arr)-1):
        if prefix_arr[i-1] == prefix_arr[len(arr)-1] - prefix_arr[i]:
            flag = True
            break

    if flag or len(arr)==1:
        return "YES"
    else:
        return "NO" 
    
T = int(input().strip())

for T_itr in range(T):
    n = int(input().strip())
    arr = list(map(int, input().rstrip().split()))
    result = balancedSums(arr)