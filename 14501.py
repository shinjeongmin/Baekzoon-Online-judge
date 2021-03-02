import sys
input = sys.stdin.readline

n=int(input())
sangdam=list()
dp=[0]*(n)
for _ in range(n):
    t,p=map(int,input().split())
    sangdam.append((t,p))
    dp[_]=sangdam[_][1]

for i in range(n):
    if i + sangdam[i][0]>n:
        dp[i]=0
        continue
    t=dp[i]
    for j in range(i+sangdam[i][0],n):
        if t+sangdam[j][1] > dp[j]:
            dp[j] = t+sangdam[j][1]
print(max(dp))