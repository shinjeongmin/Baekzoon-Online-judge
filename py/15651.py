import sys
input = sys.stdin.readline
from itertools import product

n,m=map(int,input().split())
numbers=list(i for i in range(1,n+1))
suyeol=list(map(list,product(numbers,repeat=m)))
for i in suyeol:
    for j in i:
        print(j,end=' ')
    print()