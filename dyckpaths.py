from itertools import permutations
N=int(input())
l=[]
for i in range(0,N):
    l.append('x')
    l.append('y')
p = set(list(permutations(l,2*N)))
count=0
for seq in p:
    flag=1
    check=[]
    for let in seq:
        try:
            if let=='x':
                check.append('x')
            else:
                check.pop()
        except:
            flag=0
            break       
    if flag==1 and len(check)==0:
        count+=1

print(count)
    
        
        
        
