import sys
input = sys.stdin.readline

n=list(input().rstrip())
alpha=[]
num=0
for i in n:
    if i.isdecimal():
        num+=int(i)
    else:
        alpha.append(i)
alpha.sort()
alpha= ''.join(map(str,alpha))
print(alpha+str(num))