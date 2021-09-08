import sys
input = sys.stdin.readline
import copy

def multiple(a,b):
    ret=0
    for i in range(m):
        ret+=a[i]*b[i]
    return ret

n,m=map(int,input().split())
A=list()
for i in range(n):
    A.append(list(map(int,input().split())))
m,k=map(int,input().split())
B=list()
for i in range(m):
    B.append(list(map(int,input().split())))

C=[[0]*k for i in range(n)]
for i in range(n):
    for j in range(k):
        temp1=A[i]
        temp2=list()
        for tempi in range(m):
            temp2.append(B[tempi][j])
        C[i][j]=multiple(temp1,temp2)
for i in C:
    for j in i:
        print(j,end=' ')
    print()