import sys
input = sys.stdin.readline

def dfs(L):
    global suyeol
    if L==m:
        for i in suyeol:
            print(i,end=' ')
        print()
    else:
        for i in numbers:
            if check[i]==0:
                suyeol.append(i)
                check[i]=1
                dfs(L+1)
                suyeol.pop()
                check[i]=0

n,m=map(int,input().split())
numbers=list(i for i in range(1,n+1))
check=[0]*(n+1)
suyeol=list()
dfs(0)

# #라이브러리 이용방법
# from itertools import permutations
#
# n,m=map(int,input().split())
# numbers=list(i for i in range(1,n+1))
# suyeol=list(map(list,permutations(numbers,m)))
# for i in suyeol:
#     for j in i:
#         print(j,end=' ')
#     print()