import sys
input = sys.stdin.readline
from collections import deque

dx=[1,2,2,1,-1,-2,-2,-1]
dy=[2,1,-1,-2,-2,-1,1,2]
T=int(input())
for t in range(T):
    I=int(input())
    chess=[[0] * I for j in range(I)]
    x,y=map(int,input().split())
    goalx,goaly=map(int,input().split())
    cnt=0
    Q=deque()
    Q.append((x,y,cnt))
    chess[x][y]=-1
    while Q:
        cx,cy,curcnt=Q.popleft()
        if cx==goalx and cy==goaly:
            cnt=curcnt
            break
        for i in range(len(dx)):
            nx=cx+dx[i]
            ny=cy+dy[i]
            if 0<=nx<I and 0<=ny<I and chess[nx][ny]==0:
                Q.append((nx,ny,curcnt+1))
                chess[nx][ny]=curcnt+1
    print(cnt)