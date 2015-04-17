import os
print "read open"
rd = open("pipe","r")
print "write open"
wd = open("pipe1","w")
print "how"
while True:	
	print rd.readline()
	print "read"
	wd.write("lol\n")
	print "written"
close(rd)
