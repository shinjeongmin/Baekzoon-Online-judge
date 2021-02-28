import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

def movecnt(cur,cnt):
    global maxcnt
    check[cur]=1
    next=cur+panel[cur]
    if check[next]==0:
        return movecnt(next,cnt+1)
    else:
        if maxcnt<cnt+1:
            maxcnt=cnt+1
        return cnt+1

n=int(input())
panel=list(map(int,input().split()))
panel.insert(0,0)
dp=[0]*(n+1)
check=[0]*(n+1)
maxcnt=0
for i in range(1,4):
    # 배열 일일이 초기화
    check=[0]*(n+1)
    movecnt(i,1)
print(maxcnt)