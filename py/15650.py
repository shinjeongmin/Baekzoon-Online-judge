import sys
input = sys.stdin.readline
from itertools import combinations

n,m=map(int,input().split())
numbers=list(i for i in range(1,n+1))
suyeol=list(map(list,combinations(numbers,m)))
for i in suyeol:
    for j in i:
        print(j,end=' ')
    print()