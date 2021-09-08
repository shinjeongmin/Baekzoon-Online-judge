import sys
input = sys.stdin.readline

t=int(input())
for _ in range(t):
    n=int(input())
    # 0 - open, 1 - close
    dp=[0]+[1]*(n)
    for i in range(2,n+1):
        for j in range(i,n+1,i):
            if dp[j]==0:
                dp[j]=1
            else:
                dp[j]=0
    print(sum(dp))