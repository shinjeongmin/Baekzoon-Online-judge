import sys
input = sys.stdin.readline

def slice(side,x,y):
    global blue,white
    # 종이가 한 칸일 경우
    if side==1:
        if paper[x][y]==0:
            white+=1
        else:
            blue+=1
        return
    # 자른 색종이 확인
    total=0
    for i in range(x,x+side):
        for j in range(y,y+side):
            if paper[i][j]==1:
                total+=1

    if total==(side**2):
        blue+=1
    elif total==0:
        white+=1
    else:
        slice(side//2,x,y)
        slice(side//2,x,y+side//2)
        slice(side//2,x+side//2,y)
        slice(side//2,x+side//2,y+side//2)

n=int(input())
paper=list()
blue=0
white=0
for i in range(n):
    paper.append(list(map(int,input().split())))
slice(n,0,0)
print(white)
print(blue)