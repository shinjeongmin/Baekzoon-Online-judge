import sys
input = sys.stdin.readline

sik=input().rstrip()
res=0
prevOper='+'
minusAppear=False
num=""
for i in sik:
    if i.isdigit():
        num+=i
    else:
        if prevOper=='+' and minusAppear==False:
            res+=int(num)
            num=""
        else:
            res-=int(num)
            num=""
        if i=='-':
            prevOper='-'
            minusAppear=True
        else:
            prevOper='+'
if prevOper=='+' and minusAppear==False:
    res+=int(num)
    num=""
else:
    res-=int(num)
    num=""
print(res)