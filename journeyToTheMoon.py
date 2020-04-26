import math
import os
import random
import re
import sys
from collections import defaultdict

array = []

# Complete the journeyToMoon function below.
def union(u,v):
    global array
    value = array[v]
    replace_value = array[u]
    for i,ele in enumerate(array):
        if ele == replace_value:
            array[i] = value
    
def journeyToMoon(n, astronaut):
    global array
    for i in range(0,n):
        array.append(i)

    for el in astronaut:
        union(el[0],el[1])
    print(array)

    dic = defaultdict(int)
    for el in array:
        dic[el]+=1
    
    res = 0
    summ = 0
    valuesarr= list(dic.values())
    
    for i in valuesarr:
        res +=summ*i
        summ+=i
    
    return res


    

np = input().split()
n = int(np[0])
p = int(np[1])
astronaut = []

for _ in range(p):
    astronaut.append(list(map(int, input().rstrip().split())))

result = journeyToMoon(n, astronaut)

print(result)