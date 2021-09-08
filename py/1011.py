import sys
input = sys.stdin.readline

T=int(input())
for t in range(T):
    x,y=map(int,input().split())
    distance=y-x
    count=0
    move=1
    totalmove=0
    while totalmove<distance:
        count+=1
        totalmove+=move
        if count%2==0:
            move+=1
    print(count)