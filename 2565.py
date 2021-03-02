import sys
input = sys.stdin.readline

n=int(input())
jul=list()
dp=[0]*100
dp[0]=1
for i in range(n):
    jul.append(tuple(map(int,input().split())))
jul.sort(key=lambda x:x[0])
for i in range(n):
    maxval=1
    for j in range(i):
        if jul[i][1]>jul[j][1]:
            maxval=max(dp[j]+1,maxval)
    dp[i]=maxval
print(n-max(dp))