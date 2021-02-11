import sys
input = sys.stdin.readline
n=int(input())
fib=[0]*(n+2)
fib[0]=0
fib[1]=1
for i in range(n):
    fib[i+2]=fib[i+1]+fib[i]
print(fib[n])