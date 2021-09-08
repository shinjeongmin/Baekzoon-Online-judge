import sys
input = sys.stdin.readline
from itertools import combinations

n,k=map(int,input().split())
data=[]
for i in range(1,n+1):
    data.append(i)
print(len(list(combinations(data,k))))