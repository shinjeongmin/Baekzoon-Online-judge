import sys
input = sys.stdin.readline
from collections import deque

def dfs(L):
    check[L]=1
    print(L,end=' ')
    for i in range(1,n+1):
        if panel[L][i]==1 and check[i]==0:
            dfs(i)

def bfs(L):
    check[L]=1
    Q=deque()
    Q.append(L)
    while Q:
        now=Q.popleft()
        print(now,end=' ')
        for i in range(1,n+1):
            if panel[now][i]==1 and check[i]==0:
                Q.append(i)
                check[i]=1

n,m,v=map(int,input().split())
panel=[[0]*(n+1) for i in range(n+1)]
for i in range(m):
    s,e=map(int,input().split())
    panel[s][e]=1
    panel[e][s]=1
check=[0]*(n+1)
dfs(v)
print()
check=[0]*(n+1)
bfs(v)