import sys
input = sys.stdin.readline

def slice(side,x,y):
    global result
    # 한칸인지 확인
    if side==1:
        if video[x][y]=='1':
            result.append('1')
        else:
            result.append('0')
        return
    # 자른 영상 확인
    total=0
    for i in range(x,x+side):
        for j in range(y,y+side):
            if video[i][j]=='1':
                total+=1
    if total==side**2:
        result.append('1')
    elif total==0:
        result.append('0')
    else:
        result.append('(')
        slice(side//2,x,y)
        slice(side//2,x,y+side//2)
        slice(side//2,x+side//2,y)
        slice(side//2,x+side//2,y+side//2)
        result.append(')')

n=int(input())
video=list()
result=list()
for i in range(n):
    video.append(list(input().rstrip()))
slice(n,0,0)
print(''.join(map(str,result)))