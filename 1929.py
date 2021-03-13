import sys
input = sys.stdin.readline

m,n=map(int,input().split())
L=[0]*2+[1]*(n-1)
for i in range(2,n//2):
    for j in range(i*2,n+1,i):
        L[j]=0
for i in range(m,n+1):
    if L[i]==1:
        print(i)