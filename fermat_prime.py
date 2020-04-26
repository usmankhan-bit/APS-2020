def __gcd(a, b):

    if(b == 0):
        return a
    else:
        return __gcd(b, a % b)

def power(x, y, m):

    if (y == 0):
        return 1
    p = power(x, y // 2, m) % m
    p = (p * p) % m

    return p if(y % 2 == 0) else (x * p) % m

def modInverse(a, m):

    if (__gcd(a, m) != 1):
        print("Inverse doesn't exist")

    else:
        print("Modular multiplicative inverse is ",
              power(a, m - 2, m))


a,m = map(int,input().split())
modInverse(a, m)