import sys
input = sys.stdin.readline

k,n=map(int,input().split())
lan=list(int(input()) for i in range(k))
result=0
start,end=1,max(lan)
while start<=end:
    mid=(start+end)//2
    # 잘라나오는 랜선 개수 구하기
    lanNum=sum(i//mid for i in lan)
    if lanNum>=n:
        result=mid
        start=mid+1
    elif lanNum<n:
        end=mid-1
print(result)