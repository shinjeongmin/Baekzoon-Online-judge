import sys
input = sys.stdin.readline

n=int(input())
meet=list()
for _ in range(n):
    s,e=map(int,input().split())
    meet.append((s,e))
meet.sort(key=lambda x: (x[1], x[0]))
cnt=0
meetend=0
for i in meet:
    if meetend<=i[0]:
        meetend=i[1]
        cnt+=1
print(cnt)