import sys
input = sys.stdin.readline

n,c=map(int,input().split())
wifi=list(int(input()) for i in range(n))
wifi.sort()
start,end=1,wifi[-1]
result=0
while start<=end:
    mid=(start+end)//2
    s,cnt=0,1
    for i in range(1,n):
        if wifi[i]-wifi[s]>=mid:
            s=i
            cnt+=1
    if cnt<c:
        end=mid-1
    else:
        result=mid
        start=mid+1
print(result)