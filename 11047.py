import sys
input = sys.stdin.readline
import heapq

n,k=map(int,input().split())
a=list()
cnt=0
for _ in range(n):
    heapq.heappush(a, -int(input()))

while a:
    now=-heapq.heappop(a)
    while now<=k:
        k-=now
        cnt+=1
print(cnt)