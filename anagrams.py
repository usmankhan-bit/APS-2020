#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the makingAnagrams function below.
def makingAnagrams(s1, s2):
    buffer = [0] * 26
    for char in s1: 
        buffer[ord(char) - ord('a')] += 1
    for char in s2: 
        buffer[ord(char) - ord('a')] -= 1
    return sum(map(abs, buffer)) 

s1 = input()
s2 = input()
result = makingAnagrams(s1, s2)
print(result)
