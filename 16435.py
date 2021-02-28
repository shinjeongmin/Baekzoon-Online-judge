import sys
input = sys.stdin.readline

import heapq
n,l=map(int,input().split())
apple=list(map(int,input().split()))
fruit=list()
for i in apple:
    heapq.heappush(fruit,i)

while fruit:
    temp=heapq.heappop(fruit)
    if temp<=l:
        l+=1
    else:
        break
print(l)