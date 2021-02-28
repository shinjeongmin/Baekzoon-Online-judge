import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**5)

# 함수 매개변수로 리스트의 레퍼런스를 전달하면 메모리 초과
def find_parent(x):
    if parent[x] == x:
        return x

    parent[x]=find_parent(parent[x])
    return parent[x]

def union_parent(a,b):
    a = find_parent(a)
    b = find_parent(b)
    if a<b:
        parent[b]=a
    else:
        parent[a]=b

n,m=map(int,input().split())
parent=[0]*(n+1)

for i in range(1,n+1):
    parent[i]=i

for _ in range(m):
    oper,a,b=map(int,input().split())
    if oper==1:
        if find_parent(a)==find_parent(b):
            print('YES')
        else:
            print('NO')
    else:
        union_parent(a,b)
