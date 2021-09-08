import sys
input = sys.stdin.readline
from collections import deque

n,k=map(int,input().split())
distance=[0]*(int(1e5)+1)
distance[n]=-1
time=0
Q=deque()
Q.append((n,0))
while Q:
    pos,curtime=Q.popleft()
    if pos==k:
        time=curtime
        break
    # 이동방법
    if pos+1<=int(1e5) and distance[pos+1]==0:
        Q.append((pos+1,curtime+1))
        distance[pos+1]=curtime+1
    if pos-1>=0 and distance[pos-1]==0:
        Q.append((pos-1,curtime+1))
        distance[pos-1]=curtime+1
    if pos*2<=int(1e5) and distance[pos*2]==0:
        Q.append((pos*2,curtime+1))
        distance[pos*2]=curtime+1
print(time)