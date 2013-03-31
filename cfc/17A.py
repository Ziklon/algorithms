import math
L=[1]*1001
A=[]

for i in range(2,32):
    if L[i]==1:
        for j in range(i*i,1001,i):
            L[j]=0


def isNolbach(n):
    for i  in range(len(A)-1):
        if (A[i]+A[i+1]+1) == n:
            return True
    return False 

n,k = [int(x) for x in raw_input().split()]

ans=0
for i in range(2,n+1):
    if L[i]==1:
        A.append(i)

for i in range(2,n+1):
    if L[i]==1 and isNolbach(i):
        ans=ans+1
if ans>=k:
    print 'YES'
else:
    print 'NO'
    

