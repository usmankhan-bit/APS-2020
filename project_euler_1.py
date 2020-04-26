import math

t = int(input().strip())
for a0 in range(t):
    n = int(input())
    n-=1
    count_3=n//3
    count_5=n//5
    count_15=n//15
    sum_3=(count_3*(2*3+(count_3-1)*3))>>1
    sum_5=(count_5*(2*5+(count_5-1)*5))>>1
    sum_15=(count_15*(2*15+(count_15-1)*15))>>1
    res=sum_3+sum_5-sum_15
    # print(sum_3,sum_5,sum_15)
    print(int(res))
