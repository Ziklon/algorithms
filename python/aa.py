
input=open("D:/input.txt","r")
output=open("D:/output.txt","w")
n=int(input.readline())
for c in range(n):
	L=[int(x) for x in input.readline().split()]
	ans=max(L[0]+L[1],L[2]+L[3])
	print "Caso #%d: %d" %(c+1,ans)
	output.write("Caso #%d: %d\n" %(c+1,ans))
	




