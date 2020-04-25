h=[0,2,9,7,6,5,8]
n=6
for i in range(int(n/2),0,-1):
    k=i
    heap=False
    v=h[k]
    while not heap and 2*k<=n:
        j=2*k
        if 2*k < n:
            if h[j]<h[j+1]:
                j=j+1
        if v < h[j]:
            h[k]=h[j]
            k=j
        else:
            heap=True
    h[k]=v

print(*h[1:])