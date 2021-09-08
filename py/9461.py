import sys
input = sys.stdin.readline

dp=[0]*101
dp[1]=1
dp[2]=1
dp[3]=1
t=int(input())
for _ in range(t):
    n=int(input())
    if n<4:
        print(1)
    else:
        mx=0
        for i in range(4,n+1):
            dp[i]=dp[i-2]+dp[i-3]
        print(dp[n])