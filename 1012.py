import sys
input = sys.stdin.readline
from collections import deque

def dfs(x,y):
    global ground
    ground[x][y]=0
    for i in range(4):
        nx=x+dx[i]
        ny=y+dy[i]
        if 0<=nx<m and 0<=ny<n and ground[nx][ny]==1:
            dfs(nx,ny)

dx=[1,-1,0,0]
dy=[0,0,1,-1]
t=int(input())
for T in range(t):
    m,n,k=map(int,input().split())
    cnt=0
    ground=[[0]*n for i in range(m)]
    for i in range(k):
        x,y=map(int,input().split())
        ground[x][y]=1

    for i in range(m):
        for j in range(n):
            if ground[i][j]==1:
                dfs(i,j)
                cnt+=1
    print(cnt)