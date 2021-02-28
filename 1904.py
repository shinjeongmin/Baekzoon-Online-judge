import sys
input = sys.stdin.readline

n=int(input())
dp=[0]*(1000000+1) # n으로 하면 0,1,2의 경우를 예외처리 해주어야 OutOfIndex가 안나옴
dp[1]=1
dp[2]=2
for i in range(3,n+1):
    dp[i]=(dp[i-1]+dp[i-2])%15746
print(dp[n])
