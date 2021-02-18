import sys
input = sys.stdin.readline

n=list(input().rstrip())
l=len(n)//2
n1=map(int,n[0:l])
n2=map(int,n[l:])
if sum(n1)==sum(n2):
    print('LUCKY')
else:
    print('READY')