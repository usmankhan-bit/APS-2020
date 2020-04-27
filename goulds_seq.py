def gouldSequence(n): 
  
    for row_num in range (1, n):  
      
        count = 1
        c = 1
  
        for i in range (1, row_num):
            c = c * (row_num - i) / i 

            if (c % 2 == 1): 
                count += 1
  
        print(count, end = " ") 
          
n = 16; 
  
gouldSequence(n) 