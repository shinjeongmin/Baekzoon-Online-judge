import sys
input = sys.stdin.readline
n,m=map(int,input().split())
a = list(map(int,input().split()))
s,e=0,1
sum=a[s]
cnt=0
while s!=n:
    if sum<m and e<n:
        e+=1
        sum+=a[e-1]
    else:
        if sum==m:
            cnt+=1
        sum-=a[s]
        s+=1
print(cnt)
