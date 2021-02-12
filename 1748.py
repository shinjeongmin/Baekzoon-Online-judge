import sys
input = sys.stdin.readline
from collections import deque

n=input().rstrip()
sum=0
for i in range(1,len(n)):
    sum+=(10**(i-1))*9*i
len=len(n)
sum+= (int(n)-10**(len-1)+1)*(len)
print(sum)