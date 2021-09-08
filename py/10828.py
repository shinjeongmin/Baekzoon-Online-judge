import sys
input = sys.stdin.readline
from collections import deque

n=int(input())
Q=deque()
for i in range(n):
    com=input().split()
    if com[0]=='push':
        Q.append(int(com[1]))
    elif com[0]=='pop':
        if Q:
            print(Q.pop())
        else:
            print(-1)
    elif com[0]=='size':
        print(len(Q))
    elif com[0]=='empty':
        print(1 if len(Q)==0 else 0)
    elif com[0]=='top':
        if Q:
            print(Q[-1])
        else:
            print(-1)