import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

n=int(input())
time= [0] * (10**4+1)
for i in range(1,n**2+1):
    dodugi=list(map(int,input().split()))
    dodugi.pop(0)
    dodugi.pop(0)
    for j in range(len(dodugi)):
        #print(j,dodugi[j])
        # 해당 초에서 더 나은 점수이면 바꿈
        time[dodugi[j]]=i
print(sum(time))