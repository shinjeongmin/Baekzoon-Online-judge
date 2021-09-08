import sys
input = sys.stdin.readline

n=int(input())
p=list(map(int,input().split()))
multi=[i for i in range(n,0,-1)]
p.sort()
res=0
for i in range(n):
    res+=p[i]*multi[i]
print(res)