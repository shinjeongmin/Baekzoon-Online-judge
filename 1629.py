import sys
input = sys.stdin.readline

def power(A,B):
    if B==1:
        return A%c
    else:
        result = power(A,B//2)
        if B%2==0:
            return result**2%c
        else:
            return result**2*A%c

a,b,c=map(int,input().split())
print(power(a,b))