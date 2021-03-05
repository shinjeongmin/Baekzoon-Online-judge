import sys
input = sys.stdin.readline
import heapq

n=int(input())
heap=list()
for i in range(n):
    x=int(input())
    if x!=0:
        heapq.heappush(heap,-x)
    else:
        if heap:
            print(-heapq.heappop(heap))
        else:
            print(0)