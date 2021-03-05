import sys
input = sys.stdin.readline
import heapq

plush=list()
minush=list()
n=int(input())
for i in range(n):
    x=int(input())
    if x>0:
        heapq.heappush(plush,x)
    elif x<0:
        heapq.heappush(minush,-x)
    else:
        # plus힙과 minus힙의 첫 인덱스 값 비교
        if plush and minush:
            if plush[0]<minush[0]:
                print(heapq.heappop(plush))
            else:
                print(-heapq.heappop(minush))
        elif plush:
            print(heapq.heappop(plush))
        elif minush:
            print(-heapq.heappop(minush))
        else:
            print(0)
