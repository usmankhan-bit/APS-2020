def genearte_binomial_coef(n,k):
    table=[]
    table = [[0 for j in range(i+1)] for i in range(n+1)]
        
    for i in range(n+1):
        for j in range(len(table[i])):
            if j == 0 or i == j:
                table[i][j] = 1
            else:
                table[i][j] = table[i-1][j] + table[i-1][j-1]

    print(table)
    print(table[n][k])

genearte_binomial_coef(5,4)