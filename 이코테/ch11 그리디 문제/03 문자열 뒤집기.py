import sys
input = sys.stdin.readline

zero=0
one=0
s=list(map(int,list(input().rstrip())))
cur=-1
for i in s:
    if cur!=i:
        if i==0:
            zero+=1
        else:
            one+=1
        cur=i
print(min(zero,one))
print(zero,one)