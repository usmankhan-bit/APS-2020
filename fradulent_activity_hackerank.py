import math
import os
import random
import re
import sys
import statistics

# Complete the activityNotifications function below.
count_arr = [0]*201
def counting_sort(array):
    for exp in array:
        count_arr[exp]+=1

def get_median(d,median_pos):
    global count_arr
    counter,left = 0,0

    while counter<median_pos:
        counter+=count_arr[left]
        left+=1
    
    right = left
    left -= 1

    if counter>median_pos or d%2!=0:
        return left
    else:
        while count_arr[right] == 0:
            right+=1
        return (left+right)/2

def activityNotifications(expenditure, d):
    global count_arr
    index = 0
    count = 0
    end = d
    counting_sort(expenditure[0:d]) 
    if d%2 == 0:
        median_pos = int(d/2)
    else:
        median_pos = int(d/2)+1

    for i in range(d,len(expenditure)):
        median = get_median(d,median_pos)
        if expenditure[i]>=2*median:
            count+=1
        count_arr[expenditure[index]]-=1
        count_arr[expenditure[end]]+=1
        index+=1
        end+=1
    return count


nd = input().split()
n = int(nd[0])
d = int(nd[1])
expenditure = list(map(int, input().rstrip().split()))
result = activityNotifications(expenditure, d)
print(result)