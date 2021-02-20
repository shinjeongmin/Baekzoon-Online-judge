import sys
input = sys.stdin.readline

def minimumval(n):
    result=0
    for i in range(1,n+1):
        result+=i
    return result

n,k=map(int,input().split())
bowl=[i for i in range(1,k+1)]
if minimumval(k)>n:
    print(-1)
else:
    n-=minimumval(k)
    if n%k==0:
        print(k-1)
    else:
        print(k)