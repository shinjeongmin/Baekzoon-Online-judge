import sys
input = sys.stdin.readline

n=int(input())
dp=[0]*(n+1)
sq=[i*i for i in range(1,317)]
for i in range(1,n+1):
    s=[]
    for j in sq:
        if j>i:
            break
        s.append(dp[i-j])
    dp[i]=min(s)+1
print(dp[n])