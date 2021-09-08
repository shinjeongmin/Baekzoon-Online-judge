import sys
input = sys.stdin.readline
from collections import deque

n,m=map(int,input().split())
numbers=[i for i in range(1,n+1)]
numbers=deque(numbers)
ppop=list(map(int,input().split()))
result=0
for p in ppop:
    cnt=0
    # 큐의 맨 왼 쪽 값이 뽑아낼 수와 다른 경우
    if p!=numbers[0]:
        # 왼쪽이동이 가까운이 오른쪽이동이 가까운지 탐색
        cnt=1
        while True:
            if numbers[cnt]==p:
                break
            if numbers[-cnt]==p:
                cnt*=(-1)
                break
            cnt+=1
        #print(p,cnt)
    # 큐 이동
    if cnt>=0:
        for i in range(cnt):
            numbers.append(numbers.popleft())
    else:
        for i in range(abs(cnt)):
            numbers.appendleft(numbers.pop())
    if p==numbers[0]:
        #print(numbers[0],' 적출')
        numbers.popleft()
        result+=abs(cnt)
print(result)