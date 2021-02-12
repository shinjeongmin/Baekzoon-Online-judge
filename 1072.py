import sys
input = sys.stdin.readline
import math
x,y=map(int,input().split())
z=math.floor(y*100/x)
s,e=1,1000000000
while s<e:
    m=(s+e)//2
    mv=int((y+m)*100/(x+m))
    if mv <= z:
        s=m+1
    else:
        e=m
if int((y+e)*100/(x+e))>z:
    print(e)
else:
    print(-1)