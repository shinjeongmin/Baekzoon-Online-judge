import sys
input = sys.stdin.readline
from itertools import product
import copy

def moveUp(bod):
    global n
    sumcheck=[[0]*n for i in range(n)]
    for i in range(n):
        for j in range(n):
            # 비었으면 넘어감
            if bod[i][j]==0:
                continue
            # 아니라면 위로 쭉 밀기
            else:
                tempi=i-1
                # 바로 위칸이 0이 아닐 때까지 값 밀어올리기
                while tempi>=0 and bod[tempi][j]==0:
                    bod[tempi][j]=bod[tempi+1][j]
                    bod[tempi+1][j]=0
                    tempi-=1
                # 밀어올린 후 위의 값이 있을때, 수가 같으면 합침
                if tempi>=0 and bod[tempi][j]==bod[tempi+1][j] and sumcheck[tempi][j]==0:
                    bod[tempi][j]*=2
                    bod[tempi+1][j]=0
                    sumcheck[tempi][j]=1
        # for i in bod:
        #     print(i)
        # print()

def moveDown(bod):
    global n
    sumcheck=[[0]*n for i in range(n)]
    for i in range(n-1,-1,-1):
        for j in range(n):
            # 비었으면 넘어감
            if bod[i][j]==0:
                continue
            # 아니라면 아래로 쭉 밀기
            else:
                tempi=i+1
                # 바로 아래칸이 n이 아닐 때까지 값 밀어내리기
                while tempi<n and bod[tempi][j]==0:
                    bod[tempi][j]=bod[tempi-1][j]
                    bod[tempi-1][j]=0
                    tempi+=1
                # 밀어내린 후 아래의 값이 있을때, 수가 같으면 합침
                if tempi<n and bod[tempi][j]==bod[tempi-1][j] and sumcheck[tempi][j]==0:
                    bod[tempi][j]*=2
                    bod[tempi-1][j]=0
                    sumcheck[tempi][j]=1
        # for i in bod:
        #     print(i)
        # print()

def moveLeft(bod):
    global n
    sumcheck=[[0]*n for i in range(n)]
    for j in range(n):
        for i in range(n):
            # 비었으면 넘어감
            if bod[i][j]==0:
                continue
            # 아니라면 좌로 쭉 밀기
            else:
                tempj=j-1
                # 바로 왼칸이 0미만이 아닐 때까지 값 밀기
                while tempj>=0 and bod[i][tempj]==0:
                    bod[i][tempj]=bod[i][tempj+1]
                    bod[i][tempj+1]=0
                    tempj-=1
                # 민 후 왼 값이 있을때, 수가 같으면 합침
                if tempj>=0 and bod[i][tempj]==bod[i][tempj+1] and sumcheck[i][tempj]==0:
                    bod[i][tempj]*=2
                    bod[i][tempj+1]=0
                    sumcheck[i][tempj]=1
        # for i in bod:
        #     print(i)
        # print()

def moveRight(bod):
    global n
    sumcheck=[[0]*n for i in range(n)]
    for j in range(n-1,-1,-1):
        for i in range(n):
            # 비었으면 넘어감
            if bod[i][j]==0:
                continue
            # 아니라면 우로 쭉 밀기
            else:
                tempj=j+1
                # 바로 오른칸이 n이 아닐 때까지 값 밀기
                while tempj<n and bod[i][tempj]==0:
                    bod[i][tempj]=bod[i][tempj-1]
                    bod[i][tempj-1]=0
                    tempj+=1
                # 민 후 오른값이 있을때, 수가 같으면 합침
                if tempj<n and bod[i][tempj]==bod[i][tempj-1] and sumcheck[i][tempj]==0:
                    bod[i][tempj]*=2
                    bod[i][tempj-1]=0
                    sumcheck[i][tempj]=1
        # for i in bod:
        #     print(i)
        # print()

def findmax(bod):
    global n
    mx=0
    for i in range(n):
        for j in range(n):
            mx=max(mx,bod[i][j])
    return mx

if __name__=="__main__":
    n=int(input())
    # 최대 이동 횟수
    movecnt=5
    # 결과
    mostmaxnum=0
    board=list()
    for i in range(n):
        board.append(list(map(int,input().split())))
    # 4방향 인덱스 (itertool product를 사용하기 위함)
    movedirect=[1,2,3,4]
    # 5번 이동하는 경우의 수 (중복순열)
    movecase=list(product(movedirect,repeat= movecnt))
    for i in movecase:
        # 케이스별로 배열 깊은 복사
        tempboard=copy.deepcopy(board)
        # 이동함수 실행
        for j in i:
            # 방향별 이동
            if j==1:
                moveUp(tempboard)
            elif j==2:
                moveDown(tempboard)
            elif j==3:
                moveLeft(tempboard)
            elif j==4:
                moveRight(tempboard)
        mostmaxnum=max(findmax(tempboard),mostmaxnum)
    print(mostmaxnum)