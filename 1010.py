import sys
input = sys.stdin.readline
import math

t=int(input())
for _ in range(t):
    n,m=map(int,input().split())
    res=math.factorial(m)//(math.factorial(n)*math.factorial(m-n))
    print(res)