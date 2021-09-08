import sys
input = sys.stdin.readline

n=int(input())
cnt=2
while n!=1:
    if n%cnt==0:
        n//=cnt
        print(cnt)
    else:
        cnt+=1
