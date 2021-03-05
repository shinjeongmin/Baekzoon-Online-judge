import sys
input = sys.stdin.readline

dx=[0,0,0,1,1,1,2,2,2]
dy=[0,1,2,0,1,2,0,1,2]

def slice(side,x,y):
    global one,zero,mone
    # 한칸 일 경우
    if side==1:
        if paper[x][y]==1:
            one+=1
        elif paper[x][y]==0:
            zero+=1
        else:
            mone+=1
        return
    # 3의 거듭제곱칸일 경우
    total,zerototal=0,0
    for i in range(x,x+side):
        for j in range(y,y+side):
            # 토탈에 값이 무엇이든 일단 저장
            total+=paper[i][j]
            # 0인 경우만 따로 저장
            if paper[i][j]==0:
                zerototal+=1
    if total==side**2:
        one+=1
    elif total==(-1)*(side**2):
        mone+=1
    elif zerototal==side**2: # total 0이 1과 -1의 조합으로 나올 수 있음
        zero+=1
    else:
        nextside=side//3
        # 재귀
        for i in range(9):
            slice(nextside,x+(dx[i]*nextside),y+(dy[i]*nextside))

n=int(input())
paper=list()
one,zero,mone=0,0,0
for i in range(n):
    paper.append(list(map(int,input().split())))
slice(n,0,0)
print(mone)
print(zero)
print(one)