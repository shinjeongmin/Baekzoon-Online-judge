import sys
input = sys.stdin.readline
import copy

n=int(input())
dp=list(1 for i in range(10))
dpaft=[0]*10
for i in range(n-1):
    for j in range(10):
        if j-1>=0:
            dpaft[j-1]+=dp[j]
        if j+1<10:
            dpaft[j+1]+=dp[j]
    dp=copy.deepcopy(dpaft)
    dpaft=[0]*10
print(sum(dp[1:])%int(1e9))