import  sys
n,m=map(int,input().split())
num=list(map(int,input().split()))
num.insert(0,0)
for i in range(1,n+1):
    num[i]+=num[i-1]
result=list()
for i in range(m):
    s,e=map(int,input().split())
    res=num[e]-num[s-1]
    result.append(res)
for i in result:
    print(i)
