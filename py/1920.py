import sys
input = sys.stdin.readline

n=int(input())
A=list(map(int,input().split()))
A.sort()
m=int(input())
B=list(map(int,input().split()))
for i in B:
    start,end=0,n-1
    while start<=end:
        mid=(start+end)//2
        if i==A[mid]:
            print(1)
            break
        elif i<A[mid]:
            end=mid-1
        else:
            start=mid+1
    else:
        print(0)