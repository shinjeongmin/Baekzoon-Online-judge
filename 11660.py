import sys
n,m=map(int,sys.stdin.readline().split())
pyo=[list(map(int,sys.stdin.readline().split())) for i in range(n)]
#pyo=[list(map(int,input().split())) for i in range(n)]
for i in range(n):
    pyo[i].insert(0,0)
pyo.insert(0,[0]*(n+1))
# 누적합
for i in range(1,n+1):
    for j in range(n):
        pyo[i][j+1]+=pyo[i][j]
for i in range(1,n+1):
    for j in range(1,n):
        pyo[j+1][i]+=pyo[j][i]
# 구하기
result=list()
for i in range(m):
    x1,y1,x2,y2=map(int,sys.stdin.readline().split())
    #print(pyo[max(x1,x2)][min(y1,y2)-1],pyo[min(x1,x2)-1][max(y1,y2)], pyo[min(x1,x2)-1][min(y1,y2)-1])
    res=pyo[x2][y2]-(pyo[max(x1,x2)][min(y1,y2)-1]
                     +pyo[min(x1,x2)-1][max(y1,y2)])+pyo[min(x1,x2)-1][min(y1,y2)-1]
    result.append(res)
for i in result:
    print(i)