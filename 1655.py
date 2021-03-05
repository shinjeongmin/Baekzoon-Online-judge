import sys
input = sys.stdin.readline
import heapq

left,right=list(),list()
n=int(input())
for i in range(n):
    num=int(input())
    if len(left)==len(right):
        # 왼쪽은 가장 큰 값을 꺼내야하므로 최대힙
        heapq.heappush(left,(-num,num))
    else:
        # 오른쪽은 가장 작은 값을 꺼내야 하므로 최소힙
        heapq.heappush(right,(num,num))

    # 오른쪽 최소 값이 왼쪽 최대 값보다 큰 경우 바꾸기
    if right and left[0][1]>right[0][1]:
        leftval=heapq.heappop(left)[1]
        rightval=heapq.heappop(right)[1]
        heapq.heappush(right,(leftval,leftval))
        heapq.heappush(left,(-rightval,rightval))
    print(left[0][1])