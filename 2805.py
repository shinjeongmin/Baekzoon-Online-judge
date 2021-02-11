import sys
input = sys.stdin.readline
n,m=map(int,input().split())
tree=list(map(int,input().split()))
res=0
start,end=0,max(tree)
while start<=end:
    mid=(start+end)//2
    s=0
    for i in tree:
        if i>=mid:
            s+=i-mid
    if s>=m:
        res=mid
        start=mid+1
    else:
        end=mid-1
print(res)
