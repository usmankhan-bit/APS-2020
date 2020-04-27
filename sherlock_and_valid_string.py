import math
import os
import random
import re
import sys
CHARS = 26
# Complete the isValid function below.
def isValid(str):
  
    freq = [0]*CHARS 
  
    # freq[] : stores the frequency of each 
    # character of a string 
    for i in range(len(str)): 
        freq[ord(str[i])-ord('a')] += 1
    print(freq)
  
    # Find first character with non-zero frequency 
    freq1 = 0
    count_freq1 = 0
    for i in range(CHARS): 
      
        if (freq[i] != 0): 
          
            freq1 = freq[i] 
            count_freq1 = 1
            break
  
    # Find a character with frequency different 
    # from freq1. 
    freq2 = 0
    count_freq2 = 0
    for j in range(i+1,CHARS): 
      
        if (freq[j] != 0): 
      
            if (freq[j] == freq1): 
                count_freq1 += 1
            else: 
                count_freq2 = 1
                freq2 = freq[j] 
                break
  
    # If we find a third non-zero frequency 
    # or count of both frequencies become more 
    # than 1, then return false 
    print(freq1,freq2)
    for k in range(j+1,CHARS): 
      
        if freq[k] != 0: 
            if freq[k] == freq1: 
                count_freq1 += 1
            elif freq[k] == freq2: 
                count_freq2 += 1
            else: 
                return "NO"
  
        # If counts of both frequencies is more than 1 
        if (count_freq1 > 1 and count_freq2 > 1): 
            return "NO"
        elif count_freq1==1 and count_freq2 > 1:
            return "NO"

    return "YES"

s = input()
result = isValid(s)
print(result)