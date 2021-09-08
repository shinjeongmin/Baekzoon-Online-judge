import sys
input = sys.stdin.readline
from collections import deque

Q=deque()
gualho=list(input().rstrip())
#올바른지 체크
check=[]
for i in gualho:
    if i=='(' or i=='[':
        check.append(i)
    elif i==')':
        if check:
            if check.pop()!='(':
                print(0)
                sys.exit(0)
        else:
            print(0)
            sys.exit(0)
    elif i==']':
        if check:
            if check.pop()!='[':
                print(0)
                sys.exit(0)
        else:
            print(0)
            sys.exit(0)
# 확인후 연산
for i in gualho:
    if i==')':
        temp=0
        if not Q:
            print(0)
            sys.exit(0)
        while Q[-1]!='(':
            if Q[-1]=='[':
                print(0)
                sys.exit(0)
            temp+=Q.pop()
        Q.pop()
        if temp==0:
            temp+=2
        else:
            temp*=2
        Q.append(temp)
    elif i==']':
        temp=0
        if not Q:
            print(0)
            sys.exit(0)
        while Q[-1]!='[':
            if Q[-1]=='(':
                print(0)
                sys.exit(0)
            temp+=Q.pop()
        Q.pop()
        if temp==0:
            temp+=3
        else:
            temp*=3
        Q.append(temp)
    else:
        Q.append(i)
if '(' in Q or '[' in Q:
    print(0)
else:
    print(sum(Q))