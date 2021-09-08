import sys
input = sys.stdin.readline
from bisect import *

n=int(input())
card=list(map(int,input().split()))
card.sort()
m=int(input())
findcard=list(map(int,input().split()))

for i in findcard:
    start,end=0,n-1
    while start<=end:
        mid=(start+end)//2
        if card[mid]==i:
            # 값이 있는 경우
            total=bisect_right(card,i)-bisect_left(card,i)
            print(total,end=' ')
            break
        elif card[mid]<i:
            start=mid+1
        else:
            end=mid-1
    # 값이 없는 경우
    else:
        print(0,end=' ')

### 방법2 hasing
# import sys
# input = sys.stdin.readline
#
# n=int(input())
# card=list(map(int,input().split()))
# cardlist=[0]*(2*int(1e7)+1)
# m=int(input())
# findcard=list(map(int,input().split()))
# for i in card:
#     cardlist[i]+=1
# for i in findcard:
#     print(cardlist[i],end=' ')
###