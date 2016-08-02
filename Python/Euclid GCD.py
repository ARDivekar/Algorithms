def GCD(a,b):
    if b==0:
        return a
    return GCD(b, a%b)

print GCD(1,5)
print GCD(10,5)
print GCD(18,52)
print GCD(14645656,5342342)
