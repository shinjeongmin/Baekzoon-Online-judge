import sys
input = sys.stdin.readline

n=int(input())
A=list(map(int,input().split()))
stack=list()
result=[-1]*(n)
for i in range(n):
    if not stack:
        stack.append(i)
        continue
    while stack and A[stack[-1]]<A[i]:
        result[stack.pop()]=A[i]
    stack.append(i)
for i in result:
    print(i,end=' ')