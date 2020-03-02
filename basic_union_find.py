def union(u,v):
    global array
    value = array[v]
    replace_value = array[u]
    for i,ele in enumerate(array):
        if ele == replace_value:
            array[i] = value

def find(u,v):
    global array
    if array[u] == array[v]:
        return True
    else:
        return False
    

array = []
for i in range(0,10):
    array.append(i)

#An example
union(2,1)
union(4,3)
union(8,4)
union(9,3)
union(6,5)

print(array)

print(find(0,7))
print(find(8,9))