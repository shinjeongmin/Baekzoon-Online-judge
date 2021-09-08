import sys
input = sys.stdin.readline
Case=1
while True:
    res=0
    l,p,v=map(int,input().split())
    if l==0 and p==0 and v==0:
        break
    res+=v//p * l
    if v%p>=l:
        res+=l
    else:
        res+=v%p
    print(f"Case {Case}: {res}")
    Case+=1
