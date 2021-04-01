import sys
input = sys.stdin.readline

points=list(list(map(int,input().split())) for i in range(3))
vert=dict()
hori=dict()
for i in points:
    hori[i[0]]=hori.get(i[0],0)+1
    vert[i[1]]=vert.get(i[1],0)+1
for key,val in hori.items():
    if val==1:
        x=key
for key,val in vert.items():
    if val==1:
        y=key
print(x,y)
