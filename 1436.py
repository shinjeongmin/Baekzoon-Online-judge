import sys
input = sys.stdin.readline

n=int(input())
result=0
while n>0:
    result+=1
    if '666' in str(result):
        n-=1
print(result)