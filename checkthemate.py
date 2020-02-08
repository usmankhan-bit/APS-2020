n=int(input())
pref=[]
for i in range(n):
    pref.append(list(map(int,input().split(' '))))
flag=0
occ=[0]*n
for i in range(n):
    for j in range(n):
        ele=pref[i][j]
        if ele!=-1 and occ[ele-1]!=1:
            occ[ele-1]=1
            break
flag=0
for i in range(n):
    if occ[i]==0:
        flag=1
        print(i+1)
if flag==0:
    print("-1")