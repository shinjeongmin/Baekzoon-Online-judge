import sys
input = sys.stdin.readline

n=int(input())
grape=list()
for i in range(n):
    grape.append(int(input()))
# if n==1:
#     print(grape[0])
#     sys.exit(0)
dp=[0]*10000
dp[0]=grape[0]
dp[1]=grape[1]+grape[0]
for i in range(2,n):
    dp[i]=max(dp[i-2]+grape[i],dp[i-3]+grape[i-1]+grape[i],dp[i-1])
print(dp[n-1])