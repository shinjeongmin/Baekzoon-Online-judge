import sys
input = sys.stdin.readline

n=int(input())
suyeol=list(map(int,input().split()))
dp=[suyeol[0]]+[-1e9]*(n-1)
result=dp[0]
for i in range(1,n):
    if suyeol[i]>dp[i-1]+suyeol[i]:
        dp[i]=suyeol[i]
    else:
        dp[i]=dp[i-1]+suyeol[i]
    result=max(dp[i],result)
print(result)