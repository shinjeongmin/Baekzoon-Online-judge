import sys
input = sys.stdin.readline

n=int(input())
rst=[]
r,g,b=[int(x) for x in input().split()]
rst.append((r,g,b))
for _ in range(n-1):
    r,g,b=[int(x) for x in input().split()]
    pR,pG,pB = rst[-1]
    R=r+min(pG,pB)
    G=g+min(pB,pR)
    B=b+min(pR,pG)
    rst.append((R,G,B))
fR,fG,fB = rst[-1]
print(min(fR,fG,fB))