from math import sqrt, floor

arr = []
cnt = []
BLOCK_SIZE = 0
currAnswer = 0
maxElem = float('-inf')

def add(x):
    global currAnswer
    currAnswer -= cnt[x] * cnt[x] * x
    cnt[x] += 1
    currAnswer += cnt[x] * cnt[x] * x

def remove(x):
    global currAnswer
    currAnswer -= cnt[x] * cnt[x] * x
    cnt[x] -= 1
    currAnswer += cnt[x] * cnt[x] * x

def convIntAndGetMax(x):
    global maxElem
    x = int(x)
    if x>maxElem:
        maxElem = x
    return x

def main():
    global cnt,arr,BLOCK_SIZE, currAnswer, maxElem
    n = int(input())
    arr = list(map(convIntAndGetMax, input().split()))
    print(maxElem)
    cnt = [ 0 for _ in range(maxElem+1) ]
    q = int(input())
    queries = []
    for i in range(q):
        l,r = map(int, input().split())
        queries.append((l,r,i))
    
    BLOCK_SIZE = floor(sqrt(n))

    queries.sort(key=lambda x : x[1])
    queries.sort(key= lambda x : x[0]//BLOCK_SIZE)
    print("queries in mo's order")
    print(queries)

    mo_left = 0
    mo_right = -1
    answers = []
    for quer in queries:
        
        while(mo_right < quer[1]):
            mo_right += 1
            add(arr[mo_right])

        while(mo_right > quer[1]):
            remove(arr[mo_right])
            mo_right -= 1

        while(mo_left > quer[0]):
            mo_left -= 1
            add(arr[mo_left])
        
        while(mo_left<quer[0]):
            remove(arr[mo_left])
            mo_left += 1

        answers.append((quer[2],currAnswer))
    answers.sort()
    for answer in answers:
        print(answer[1])