import sys
import math
input = sys.stdin.readline

n,m=map(int,input().split())
arr=[list(map(int,list(input().rstrip('\n')))) for i in range(n)]
dp=[[0]*(m+1) for i in range(n+1)]
res=0
# for i in range(1,n+1):
#     for j in range(1,m+1):
#         if arr[i-1][j-1]==1:
#             dp[i][j]=min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1])+1
#             if dp[i][j]>res:
#                 res=dp[i][j]
for i in range(n):
    for j in range(m):
        if arr[i][j]==1:
            dp[i+1][j+1]=min(dp[i+1][j],dp[i][j+1],dp[i][j])+1
            if dp[i+1][j+1]>res:
                res=dp[i+1][j+1]
print(res**2)
