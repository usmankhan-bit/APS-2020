array = []

def init(n):
    global array
    for i in range(n):
        array.append(i)

def root(u):
    global array
    while u!=array[u]:
        u = array[u]
    return u

def union(u,v):
    global array
    rootu = root(u)
    rootv = root(v)

    array[rootu] = rootv

def find(u,v):
    global array
    if root(u) == root(v):
        return True
    else:
        return False

init(8)
union(0,1)
union(0,5)
union(3,4)
union(5,3)
union(1,6)

print(array)