import sys
input = sys.stdin.readline
from math import gcd

a1,a2=map(int,input().split())
b1,b2=map(int,input().split())
boonja=a1*b2+b1*a2
boonmo=a2*b2
gcd=gcd(boonja,boonmo)
if gcd!=1:
    boonja//=gcd
    boonmo//=gcd
print(boonja,boonmo)