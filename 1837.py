import sys
input = sys.stdin.readline

pw,k=map(int,input().split())
p,q=2,pw-1
while pw%p!=0:
    p+=1
    if p>k:
        break
q=pw//p
if p<k or q<k:
    print('BAD',p)
else:
    print('GOOD')