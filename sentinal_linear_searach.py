arr=[3,5,6,4,7,35,2]
searchelement=2
n=len(arr)

temp=arr[n-1]
arr[n-1]=searchelement

i=0
while arr[i]!=searchelement:
    i+=1
arr[n-1]=temp

if i<(n-1) or arr[n-1]==searchelement:
    print("Found at ",i)
else:
    print("Not Found")