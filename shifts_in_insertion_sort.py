def getSum( BITree, index): 
    sum = 0 # Initialize result  
      
    # Traverse ancestors of BITree[index]  
    while (index > 0):  
  
        # Add current element of BITree to sum  
        sum += BITree[index]  
  
        # Move index to parent node in getSum View  
        index -= index & (-index)  
  
    return sum
  
# Updates a node in Binary Index Tree (BITree)  
# at given index in BITree. The given value 
# 'val' is added to BITree[i] and all of its 
# ancestors in tree.  
def updateBIT(BITree, n, index, val): 
  
    # Traverse all ancestors and add 'val'  
    while (index <= n):  
  
        # Add 'val' to current node of BI Tree  
        BITree[index] += val  
  
        # Update index to that of parent 
        # in update View  
        index += index & (-index)  
  
# Returns count of inversions of size three  
def getInvCount(arr, n): 
  
    invcount = 0 # Initialize result  
  
    # Find maximum element in arrays  
    maxElement = max(arr) 
  
    # Create a BIT with size equal to  
    # maxElement+1 (Extra one is used  
    # so that elements can be directly  
    # be used as index) 
    BIT = [0] * (maxElement + 1)  
    for i in range(1, maxElement + 1):  
        BIT[i] = 0
    for i in range(n - 1, -1, -1): 
  
        invcount += getSum(BIT, arr[i] - 1)  
        updateBIT(BIT, maxElement, arr[i], 1)  
    return invcount  
      
# Driver code  
if __name__ =="__main__": 
    t = int(input())
    for _ in range(t):
        n = int(input())
        arr = list(map(int,input().split()))
        print(getInvCount(arr, n)) 