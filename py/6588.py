import sys
input = sys.stdin.readline

def glodbahch(num):
    for i in range(2,n+1):
        if check[i]==True:
            if check[num-i]==True:
                return (i,num-i)
    else:
        return (0,0)

check=[False,False] + [True] * 1000000

for i in range(2,1001):
    if check[i]==True:
        for j in range(i+i, 1000001,i):
            check[j]=False

while True:
    n=int(input())

    if n==0:
        break

    n1,n2=glodbahch(n)
    if n1==0 and n2==0:
        print("Goldbach's conjecture is wrong.")
    else:
        print(str(n)+" = "+str(n1)+" + "+str(n2))