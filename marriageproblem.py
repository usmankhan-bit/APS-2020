n=int(input())
male=[]
female=[]
for i in range(n):
    male.append(list(map(int,input().split(' '))))
for i in range(n):
    female.append(list(map(int,input().split(' '))))


fvisited=[0]*n #this array stores the female priority value for the assigned male
mstart=[0]*n   #the priority of the male
prop=[0]*n     #stores number of proposals for each women
mvisited=[0]*n #0 or 1 array for storing visited status of male

ind=0 #index variable
while 0 in mvisited:
    temp=mstart[ind]+1 #increamenting male priorities everytime of particular male
    while mvisited[ind]!=1:
        try:
            i=male[ind].index(temp) 
            #if female is free
            if fvisited[i]==0: 
                prop[i]+=1     
                fvisited[i]=female[ind][i]
                mvisited[ind]=1
                mstart[ind]=male[ind][i]
            #if female is occupied but the priority of the male is higher to that female
            elif fvisited[i]!=0 and female[ind][i]<fvisited[i]: 
                prop[i]+=1
                for seq in female:
                    #setting the rejected male status to 0 and mstart to the next priority
                    if seq[i]==fvisited[i]:
                        tempi=female.index(seq)
                        mvisited[tempi]=0
                        mstart[tempi]=male[tempi][i]
                        break
                fvisited[i]=female[ind][i]
                mstart[ind]=male[ind][i]
                mvisited[ind]=1
            #if female is not available and the men is of low priority than current male
            elif fvisited[i]!=0 and female[ind][i]>=fvisited[i]:
                prop[i]+=1
                temp+=1
        except ValueError:
            temp+=1
    ind+=1
    ind%=n
    # print(fvisited)
    # print(mvisited)
    # print(mstart)
    # print(prop)
    # print("-----------------")
q=int(input())
for _ in range(q):
    x=int(input())
    print(prop[x-1])




            
        



