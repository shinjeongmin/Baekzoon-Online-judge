import sys
input = sys.stdin.readline
from collections import Counter

n=int(input())
num=list()
for i in range(n):
    num.append(int(input()))
num.sort()

sansul=round(sum(num)/n)

middle=num[n//2]

most=list()
numdict=dict()
for i in num:
    numdict[i]=numdict.get(i,0)+1
maxvalue=max(list(numdict.values()))
for k,v in numdict.items():
    if v==maxvalue:
        most.append(k)
most.sort()
if len(most)==1:
    most=most[0]
else:
    most=most[1]

diffmn=max(num)-min(num)

print(sansul)
print(middle)
print(most)
print(diffmn)