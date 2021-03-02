import sys
input = sys.stdin.readline
from collections import deque

def dfs(L,res):
    global mini,maxi,oper,q,number
    if L==len(number):
        if mini>res:
            mini=res
        if maxi<res:
            maxi=res
        # for i in q:
        #     print(i,end='')
        # print('=',res)
    else:
        if oper[0]>0:
            oper[0]-=1
            q.append('+')
            q.append(number[L])
            dfs(L+1,res+number[L])
            q.pop()
            q.pop()
            oper[0]+=1
        if oper[1]>0:
            oper[1]-=1
            q.append('-')
            q.append(number[L])
            dfs(L+1,res-number[L])
            q.pop()
            q.pop()
            oper[1]+=1
        if oper[2]>0:
            oper[2]-=1
            q.append('*')
            q.append(number[L])
            dfs(L+1,res*number[L])
            q.pop()
            q.pop()
            oper[2]+=1
        if oper[3]>0:
            oper[3]-=1
            q.append('/')
            q.append(number[L])
            if res>0 and number[L]<0 or \
                    res<0 and number[L]>0 :
                dfs(L+1,(res*(-1)//number[L])*(-1))
            else:
                dfs(L+1,res//number[L])
            q.pop()
            q.pop()
            oper[3]+=1

n=int(input())
number=list(map(int,input().split()))
oper=list(map(int,input().split())) # +,-,*,/s
mini,maxi=1e9,-1e9
q=deque()
q.append(number[0])
dfs(1,number[0])
print(maxi)
print(mini)