def generate_binomial_coef(n,k):
    if n==k or k == 0:
        return 1
    else: 
        return generate_binomial_coef(n-1,k-1) + generate_binomial_coef(n-1,k)

print(generate_binomial_coef(0,0))