import sys
input = sys.stdin.readline
from collections import deque

n,k=map(int,input().split())
Q=deque([i for i in range(1,n+1)])
cnt=0
result=list()
while Q:
    if cnt==k-1:
        result.append(Q.popleft())
    else:
        Q.append(Q.popleft())
    cnt+=1
    cnt%=k
print('<',end='')
for i in range(n-1):
    print(result[i],end=', ')
print(result[-1],end='')
print('>',end='')