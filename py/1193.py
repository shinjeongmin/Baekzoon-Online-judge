import sys
input = sys.stdin.readline

n=int(input())
maxvalue=10000000
updowntotal=0
# n번째 분수의 분모분자 총합 수를 구하기
temp=0
while True:
    if temp+updowntotal<n:
        temp+=updowntotal
        updowntotal+=1
    else:
        break
updowntotal+=1
bunmo=0
bunja=0
# 총합 수가 홀수이면 지그재그 상 분자가 1로 시작
if updowntotal%2!=0:
    bunja=1
    bunmo=updowntotal-1
    for i in range(n-temp-1):
        bunja+=1
        bunmo-=1
# 총합 수가 짝수이면 지그재그 상 분모가 1로 시작
else:
    bunmo=1
    bunja=updowntotal-1
    for i in range(n-temp-1):
        bunmo+=1
        bunja-=1
print(str(bunja)+'/'+str(bunmo))