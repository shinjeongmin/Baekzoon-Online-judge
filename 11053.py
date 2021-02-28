import sys
input = sys.stdin.readline

n=int(input())
suyeol=list(map(int,input().split()))
dp=[0]*(n)
dp[0]=1
for i in range(n):
    maxval=0
    for j in range(i):
        if suyeol[j]<suyeol[i] and maxval<dp[j]:
            maxval=dp[j]
    dp[i]=maxval+1
print(max(dp))