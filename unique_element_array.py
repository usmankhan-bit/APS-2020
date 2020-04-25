#!/bin/python3

import math
import os
import random
import re
import sys
from collections import defaultdict

# Complete the lonelyinteger function below.
def lonelyinteger(a):
    d=defaultdict(int)
    for el in a:
        d[el]+=1
    for k,v in d.items():
        if v==1:
            return k


n = int(input())
a = list(map(int, input().rstrip().split()))
result = lonelyinteger(a)
print(result)
