import sys
input = sys.stdin.readline

n=int(input())
mohum=list(map(int,input().split()))
mohum.sort()
result=0
count=0
for i in mohum:
    count+=1
    if count>=i:
        result+=1
        count=0
print(result)