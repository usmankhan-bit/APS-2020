def ugly(n):

    while(n%2==0):
        n=n/2
    
    while(n%3==0):
        n=n/3
    
    while(n%5==0):
        n=n/5
    
    if n==1:
        return 1
    else:
        return 0

n=20
for i in range(1,n):    
    if ugly(i):
        print(i)