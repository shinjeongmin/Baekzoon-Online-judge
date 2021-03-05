import sys
input = sys.stdin.readline

n, m=map(int, input().split())
namu=list(map(int, input().split()))
result=0
start,end=1,max(namu)
while start<=end:
    mid=(start+end)//2
    # 잘라나오는 나무 개수 구하기
    namusum=sum(i - mid if i>mid else 0 for i in namu)
    if namusum>=m:
        result=mid
        start=mid+1
    elif namusum<m:
        end=mid-1
print(result)