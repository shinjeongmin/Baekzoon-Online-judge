import sys
input = sys.stdin.readline

n,k=map(int,input().split())
elatos=[1]*(n+1)
elatos[0]=0
elatos[1]=0
cnt=0
for i in range(2,n+1):
    if elatos[i]==1:
        for j in range(i,n+1,i):
            if elatos[j]==1:
                elatos[j]=0
                cnt+=1
                if cnt==k:
                    print(j)
                    sys.exit(0)