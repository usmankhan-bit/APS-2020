graph=[]
union_array=[]

def initialize_union_array(N):
    global union_array
    for i in range(N):
        union_array.append(i)


def union(u,v):
    global union_array
    value = union_array[v]
    replace_value = union_array[u]
    for i,ele in enumerate(union_array):
        if ele == replace_value:
         union_array[i] = value

def find(u,v):
    global union_array
    if union_array[u] == union_array[v]:
        return True
    else:
        return False

def addEdge(u,v,w):
    global graph
    graph.append([u,v,w])


def kruskal():
    global graph,union_array
    result=[]

    graph=sorted(graph,key=lambda item:item[2])

    for li in graph:
        if find(li[0],li[1])==False:
            union(li[0],li[1])
            result.append(li)

    print(result)


    

N = int(input()) #no. of vertices
initialize_union_array(N)

addEdge(3,5,28)
addEdge(1,2,16)
addEdge(1,7,22)
addEdge(3,4,18)
addEdge(0,7,16)
addEdge(2,3,14)
addEdge(7,8,14)
addEdge(6,8,12)
addEdge(2,8,4)
addEdge(2,5,8)
addEdge(5,6,4)
addEdge(0,1,8)
addEdge(6,7,2)
kruskal()
