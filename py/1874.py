import sys
input = sys.stdin.readline

n=int(input())
suyeol=list()
for i in range(n):
    suyeol.append(int(input()))
numbers=list(i for i in range(n,0,-1))
stack=list()
operatorstack=list()
while suyeol:
    # 스택이 비거나 top의 수가 나와야할 값보다 작을 경우
    if not stack or stack[-1]<suyeol[0]:
        while not stack or stack[-1]!=suyeol[0]:
            stack.append(numbers.pop())
            operatorstack.append('+')
    # top의 값이 다음으로 나와야할 수열인 경우
    if stack and stack[-1]==suyeol[0]:
        while stack[-1]!=suyeol[0]:
            stack.pop()
            operatorstack.append('-')
        stack.pop()
        operatorstack.append('-')
        suyeol.pop(0)
    # top의 값보다 수열의 다음 값이 작은경우
    else:
        print('NO')
        break
else:
    for i in operatorstack:
        print(i)