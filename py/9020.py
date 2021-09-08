import sys
input = sys.stdin.readline

t=int(input())
MAX=10000-1
eratos=[0]*2 + [1]*(MAX)
#에라토스 테네스의체
for i in range(2,MAX//2+1):
    for j in range(i+i,MAX+1,i):
        eratos[j]=0
for T in range(t):
    num=int(input())
    goldpart=list()
    for i in range(2,num//2+1):
        if eratos[i]==1 and eratos[num-i]==1:
            goldpart.append((i,num-i,num-(2*i)))
    goldpart.sort(key=lambda x : x[2])
    print(goldpart[0][0], goldpart[0][1])