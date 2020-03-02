x,i = map(int , input().split(' '))
print(bin(x))
x = x & ~((1<<i))
print(bin(x))