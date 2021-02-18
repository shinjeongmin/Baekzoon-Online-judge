import sys
input = sys.stdin.readline

data=list(map(int,input().split()))
data.sort()

target = 1
for x in data:
    if target<x:
        break
    target += x

pritn(target)