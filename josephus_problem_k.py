def josephus_k(n,k):
    res = 0
    for i in range(1,n+1):
        res = (res+k)%i
    return res+1

n,k = map(int,input().split())
print(josephus_k(n,k))