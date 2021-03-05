import sys
input = sys.stdin.readline

def matrixmultiple(mtx1,mtx2):
    resultmatrix=[[0]*n for i in range(n)]
    for i in range(n):
        for j in range(n):
            for k in range(n):
                resultmatrix[i][j]+=(mtx1[i][k]*mtx2[k][j])
            resultmatrix[i][j]%=1000
    return resultmatrix

def matrixpower(mat,p):
    if p==1:
        for i in range(n):
            for j in range(n):
                mat[i][j]%=1000
        return mat
    if p%2==0:
        tempmat = matrixpower(mat,p//2)
        return matrixmultiple(tempmat,tempmat)
    else:
        return matrixmultiple(mat,matrixpower(mat,p-1))

n,b=map(int,input().split())
matrix=[list(map(int,input().split())) for i in range(n)]
result=matrixpower(matrix,b)
for i in range(n):
    for j in range(n):
        print(result[i][j],end=' ')
    print()
