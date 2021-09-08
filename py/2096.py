import sys
input = sys.stdin.readline

if __name__=="__main__":
    n=int(input())
    dpmax=[[0]*3 for i in range(2)]
    dpmin=[[0]*3 for i in range(2)]
    for i in range(n):
        oneline=list(map(int,input().split()))

        dpmax[1][0] = max(dpmax[0][0], dpmax[0][1]) + oneline[0]
        dpmin[1][0] = min(dpmin[0][0], dpmin[0][1]) + oneline[0]

        dpmax[1][1] = max(dpmax[0][0], dpmax[0][1], dpmax[0][2]) + oneline[1]
        dpmin[1][1] = min(dpmin[0][0], dpmin[0][1], dpmin[0][2]) + oneline[1]

        dpmax[1][2] = max(dpmax[0][2], dpmax[0][1]) + oneline[2]
        dpmin[1][2] = min(dpmin[0][2], dpmin[0][1]) + oneline[2]

        dpmax[0][0],dpmax[0][1],dpmax[0][2] =dpmax[1][0],dpmax[1][1],dpmax[1][2]
        dpmin[0][0],dpmin[0][1],dpmin[0][2] =dpmin[1][0],dpmin[1][1],dpmin[1][2]
    print(max(dpmax[1]), min(dpmin[1]))
