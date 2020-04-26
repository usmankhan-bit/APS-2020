def gcd(a,b): 
    if a == 0: 
        return b 
    return gcd(b % a, a) 

def lcm(a,b): 
    return (a*b) / gcd(a,b) 

a = 15 
b = 20
print('LCM of', a, 'and', b, 'is', lcm(a, b)) 