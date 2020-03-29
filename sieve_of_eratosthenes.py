def sieve_of_eratosthenes(n):
    array = [True for i in range(n+1)]
    p = 2
    while p*p<=n:
        if array[p]==True:
            for i in range(p*p,n+1,p):
                array[i] = False
        p+=1
    for p in range(2,n+1):
        if array[p]:
            print(p,end=" ")
    print("\n")

n = 30
sieve_of_eratosthenes(n)