import sys
input = sys.stdin.readline

n=int(input())
dp=[0] * (10**6+1)
dp[1]=0
dp[2]=1
dp[3]=1
for i in range(4,n+1):
    dp[i]=dp[i-1]+1
    if i%3==0:
        dp[i]=min(dp[i//3]+1,dp[i])
    if i%2==0:
        dp[i]=min(dp[i//2]+1,dp[i])

print(dp[n])