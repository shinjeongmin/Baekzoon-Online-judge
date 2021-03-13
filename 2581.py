import sys
input = sys.stdin.readline

m,n=map(int,[input() for i in range(2)])
total=0
minimum=1e9
for i in range(m,n+1):
    if i<2:
        continue
    for j in range(2,i):
        if i%j==0:
            break
    else:
        if i<minimum:
            minimum=i
        total+=i
if total==0:
    print(-1)
    exit(0)
print(total)
print(minimum)