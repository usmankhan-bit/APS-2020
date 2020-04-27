import math
import os
import random
import re
import sys

# Complete the gameOfThrones function below.
def gameOfThrones(s):
    l=[]
    for i in s:
        if i not in l:
            l.append(i)
        else:
            l.remove(i)
    if len(s)%2==0 and len(l)==0 or len(s)%2==1 and len(l)==1:
        return "YES"
    else:
        return "NO"

s = input()
result = gameOfThrones(s)
print(result)
