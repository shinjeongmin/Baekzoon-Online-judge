import sys
input = sys.stdin.readline
from collections import deque

def bfs():
    global maxday
    Q=deque()
    day=0
    for z in range(h):
        for y in range(m):
            for x in range(n):
                if tomato[z][y][x]==1:
                    Q.append((x,y,z,day))
    while Q:
        cx,cy,cz,curday=Q.popleft()
        for i in range(len(dx)):
            nx=cx+dx[i]
            ny=cy+dy[i]
            nz=cz+dz[i]
            if 0<=nx<n and 0<=ny<m and 0<=nz<h and tomato[nz][ny][nx]==0:
                Q.append((nx,ny,nz,curday+1))
                tomato[nz][ny][nx]=curday+1
                if curday+1>maxday:
                    maxday=curday+1

dx=[1,-1,0,0,0,0]
dy=[0,0,1,-1,0,0]
dz=[0,0,0,0,1,-1]
n,m,h=map(int,input().split())
tomato=list(list(list(map(int,input().split())) for i in range(m)) for j in range(h))
maxday=0
bfs()
for i in tomato:
    for j in i:
        for k in j:
            if k==0:
                print(-1)
                exit(0)
else:
    print(maxday)