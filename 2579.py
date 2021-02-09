import sys

n=int(sys.stdin.readline())
stage=list(int(sys.stdin.readline()) for i in range(n))
dp=[0]*(n)
if n==1:
    print(stage[0])
elif n==2:
    print(stage[0]+stage[1])
else:
    dp[0]=stage[0]
    dp[1]=stage[1]+dp[0]
    dp[2]=max(dp[0]+stage[2],stage[1]+stage[2])
    for i in range(3,n):
        dp[i]=max(dp[i-2]+stage[i],dp[i-3]+stage[i-1]+stage[i])
    print(dp[n-1])