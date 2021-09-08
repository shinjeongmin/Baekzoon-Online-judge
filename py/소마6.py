import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

n=int(input())
L=list(map(int,input().split()))
start,end=0,len(L)
mid=(start+end)//2
result=0
while start<end:
    if max(L[start:mid+1]) < max(L[mid+1:end]):
        result+=max(L[mid+1:end])
        start=mid+1
        mid=(start+end)//2
    else:
        result+=max(L[start:mid+1])
        end=mid+1
        mid=(start+end)//2
print(result)