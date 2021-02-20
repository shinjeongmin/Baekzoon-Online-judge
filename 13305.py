import sys
input = sys.stdin.readline

n=int(input())
dist=list(map(int,input().split()))
Biyong=list(map(int,input().split()))
curB=0
nextB=1
res=0
while curB<=nextB and nextB<n:
    if Biyong[curB]<=Biyong[nextB]:
        nextB+=1
    else:
        res+=sum(dist[curB:nextB])*Biyong[curB]
        curB=nextB
        nextB+=1
res+=sum(dist[curB:nextB])*Biyong[curB]
print(res)