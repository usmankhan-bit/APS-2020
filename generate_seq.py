array=list(map(int,input().split(' ')))
n=len(array)
for j in range(1,n+1):
    for i in range(0,n-1):
        temp=array[i]
        array[i]=array[i+1]
        array[i+1]=temp
        print(array)
