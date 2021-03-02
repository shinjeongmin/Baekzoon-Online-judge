import sys
input = sys.stdin.readline

def checkStartWhite(pan):
    cnt=0
    for i in range(8):
        for j in range(8):
            if i%2==0:
                if j%2==0 and pan[i][j]=='B':
                    cnt+=1
                if j%2!=0 and pan[i][j]=='W':
                    cnt+=1
            else:
                if j%2==0 and pan[i][j]=='W':
                    cnt+=1
                if j%2!=0 and pan[i][j]=='B':
                    cnt+=1
    return cnt

def checkStartBlack(pan):
    cnt=0
    for i in range(8):
        for j in range(8):
            if i%2==0:
                if j%2==0 and pan[i][j]=='W':
                    cnt+=1
                if j%2!=0 and pan[i][j]=='B':
                    cnt+=1
            else:
                if j%2==0 and pan[i][j]=='B':
                    cnt+=1
                if j%2!=0 and pan[i][j]=='W':
                    cnt+=1
    return cnt

m,n=map(int,input().split())
panel=list()
minicnt=1e9
for i in range(m):
    panel.append(list(input().rstrip()))
for i in range(m-8+1):
    for j in range(n-8+1):
        templist=list()
        for k in range(8):
            templist.append(panel[i+k][j:j+8])
        minicnt=min(checkStartBlack(templist),checkStartWhite(templist),minicnt)
print(minicnt)