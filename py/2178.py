import sys
input = sys.stdin.readline
from collections import deque

def bfs(x,y):
    global maze
    Q=deque()
    cnt=1
    Q.append((x,y,cnt))
    while Q:
        cx,cy,curcnt=Q.popleft()
        #maze[cx][cy]=curcnt # 해당 코드로 실행 시 큐에 중복된 좌표의 값을 넣어 재확인하는 낭비가 발생
        for i in range(4):
            nx=cx+dx[i]
            ny=cy+dy[i]
            if 0<=nx<n and 0<=ny<m and maze[nx][ny]==1:
                maze[nx][ny]=curcnt+1 # 큐에 넣는 순간 해당 칸의 탐색체크를 해주어야 메모리 절약
                Q.append((nx,ny,curcnt+1))

dx=[1,-1,0,0]
dy=[0,0,1,-1]
n,m=map(int,input().split())
maze=list(list(map(int,list(input().rstrip()))) for i in range(n))
bfs(0,0)
# for i in maze:
#     print(i)
print(maze[n-1][m-1])