def count_bits(n):
    count = 0
    while (n): 
        count += n & 1
        n >>= 1
    return count

def is_bit_set(n,i):
    if n & (1<<(i)):
        return 1
    else:
        return 0


def optimalsum(n,cost):
    dp = [float('inf') for i in range(2**n)]
    dp[0]=0
    for mask in range(0,2**n):
        x = count_bits(mask)
        for j in range(0,n):
            if is_bit_set(mask,j)==0:
                dp[mask|(1<<j)] = min(dp[mask|(1<<j)],dp[mask]+cost[x][j])
    print(dp)
    return dp[2**n - 1]

n=3
cost=[[3,2,7],[5,1,3],[2,7,2]]
min_cost=optimalsum(n,cost)
print(min_cost)
