import sys
input = sys.stdin.readline
n,s=map(int,input().split())
suyeol=list(map(int,input().split()))
start,end=0,1
sum=sum(suyeol[start:end])
res=0
while start<n:
    if sum>=s:
        if res>(end-start) or res==0:
            res=end-start
        sum-=suyeol[start]
        start+=1
    else:
        if end<n:
            end+=1
            sum+=suyeol[end-1]
        else:
            sum-=suyeol[start]
            start+=1
print(res)
