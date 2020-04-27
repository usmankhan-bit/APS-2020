import math
import os
import random
import re
import sys

# Complete the squares function below.
def squares(a, b):
    return math.floor(math.sqrt(b)) - math.ceil(math.sqrt(a)) + 1
    


q = int(input())

for q_itr in range(q):
    ab = input().split()
    a = int(ab[0])
    b = int(ab[1])
    result = squares(a, b)