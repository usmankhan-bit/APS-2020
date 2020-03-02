n = int(input())
array = []
for _ in range(n):
    array.append(int(input()))
count=[1 for _ in range(n)]
for i in range(1,n):
    for j in range(0,i):
        if array[i]>array[j] and count[j]+1>count[i]:
            count[i]=count[j]+1
print(max(count))