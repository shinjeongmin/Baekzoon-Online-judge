import sys
input = sys.stdin.readline
from collections import deque

while True:
    string=input().rstrip()
    stack=deque()
    if string=='.':
        break
    for i in string:
        if i=='(' or i=='[':
            stack.append(i)
        elif i==')':
            if not stack:
                print('no')
                break
            if stack[-1]!='(':
                print('no')
                break
            stack.pop()
        elif i==']':
            if not stack:
                print('no')
                break
            if stack[-1]!='[':
                print('no')
                break
            stack.pop()
    else:
        if stack:
            print('no')
        else:
            print('yes')