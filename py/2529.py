import sys
input = sys.stdin.readline
from itertools import permutations

def check(L):
    global n,budeung
    for i in range(n):
        if budeung[i]=='<' and L[i]>=L[i+1]:
            return False
        if budeung[i]=='>' and L[i]<=L[i+1]:
            return False
    else:
        return True

n=int(input())
budeung=list(input().rstrip().split())
numbers=[i for i in range(10)]
permu=list(permutations(numbers,n+1))
manjoksu=list()
for i in permu:
    if check(i):
        tempnum="".join(map(str,list(i)))
        manjoksu.append(tempnum)
print(manjoksu[-1])
print(manjoksu[0])