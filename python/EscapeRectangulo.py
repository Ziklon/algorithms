import re
input=open("E:/input.txt","r")
output=open("E:/output.txt","w")
n=int(input.readline())
for c in range(n):
	x,y,w,h=[int(x) for x in input.readline().split()]
	ans=min(x,min(w-x,min(h-y,y)))
	#print "Caso #%d: %d" %(c+1,ans)
	output.write("%d\n" %(ans))
output.close()
	





