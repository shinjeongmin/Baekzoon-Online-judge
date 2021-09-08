import sys
input = sys.stdin.readline

while True:
    line=list(map(int,input().split()))
    if sum(line)==0:
        break
    line.sort()
    if (line[0]**2) + (line[1]**2) ==line[2]**2:
        print('right')
    else:
        print('wrong')