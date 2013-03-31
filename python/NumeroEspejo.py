import re

def multi(n):
	ans=1
	if len(n)==0:
		return -1
	for i in range(len(n)):
		m=int(n[i])
		ans=ans*m
	return ans

input=open("E:/input.txt","r")
output=open("E:/output.txt","w")
n=int(input.readline().strip())
for c in range(n):
	num=input.readline().strip()
	ans="NO"
	for i in range(len(num)):
		a=num[0:i]
		b=num[i:]
		if multi(a)==multi(b):
			ans="YES"
	print "Caso #%d: %s" %(c+1,ans)
	output.write("Caso #%d: %s\n" %(c+1,ans))
output.close()
	





