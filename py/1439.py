import sys
input = sys.stdin.readline

s=input().rstrip()
zero=0
one=0
if s[0]=='1':
    one+=1
else:
    zero+=1
for i in range(len(s)):
    if s[i-1]!=s[i]:
        if s[i]=='1':
            one+=1
        else:
            zero+=1
print(min(zero,one))