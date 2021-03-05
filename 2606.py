import sys
input = sys.stdin.readline
from collections import deque

def bfs(L):
    cnt=0
    Q=deque()
    Q.append(L)
    while Q:
        now=Q.popleft()
        for i in range(1,n+1):
            if check[i]==0 and panel[now][i]==1:
                Q.append(i)
                check[i]=1
                cnt+=1
    return cnt

n=int(input())
m=int(input())
panel=[[0]*(n+1) for i in range(n+1)]
check=[0]*(n+1)
for i in range(m):
    s,e=map(int,input().split())
    panel[s][e]=1
    panel[e][s]=1
check[1]=1
print(bfs(1))