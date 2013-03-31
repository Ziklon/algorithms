import re
import sys
sys.stdin=open("input.txt","r")
sys.stdout=open("output.txt","w")
n,m=[int(x) for x in raw_input().split()]
r=min(n,m)
n=n-r
m=m-r
ans=""
for i in range(r):
	ans=ans+"BG"
for i in range(n):
	ans=ans+"B"
for i in range(m):
	ans=ans+"G"

print ans
