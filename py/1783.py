import sys
input = sys.stdin.readline

n,m=map(int,input().split())
res=1

# 세로 1칸인 경우 이동불가
if n==1:
    pass
# 세로 2칸인 경우
elif n==2:
    if m<3:
        pass
    else:
        while m>2:
            m-=2
            res+=1
        res=min(4,res)
# 세로 3칸 이상인 경우
else:
    if m<=4:
        res+=m-1
    elif m==6 or m==5:
        res+=3
    else:
        res+=m-3
print(res)