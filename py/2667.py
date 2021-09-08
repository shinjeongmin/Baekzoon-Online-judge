import sys
input = sys.stdin.readline
from collections import deque

dx=[1,0,-1,0]
dy=[0,1,0,-1]
n=int(input())
panel=list(list(input().rstrip()) for i in range(n))
check=[[0]*n for i in range(n)]
Q=deque()
danji=list()
for i in range(n):
    for j in range(n):
        if panel[i][j]=='1' and check[i][j]==0:
            Q.append((i,j))
            check[i][j]=1
            cnt=1
            while Q:
                now=Q.popleft()
                for k in range(4):
                    next_x=now[0]+dx[k]
                    next_y=now[1]+dy[k]
                    if 0<=next_x<n and 0<=next_y<n \
                            and panel[next_x][next_y]=='1' \
                            and check[next_x][next_y]==0:
                        check[next_x][next_y]=1
                        cnt+=1
                        Q.append((next_x,next_y))
            danji.append(cnt)
print(len(danji))
danji.sort()
for i in danji:
    print(i)