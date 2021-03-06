import cPickle 
import os
import RPi.GPIO as GPIO
import MFRC522
import signal
readpath = "./rfid_pipe1"
writepath = "./rfid_pipe2"
os.mkfifo(writepath)
continue_reading = True
# Capture SIGINT for cleanup when the script is aborted
def end_read(signal,frame):
    global continue_reading
    print "Ctrl+C captured, ending read."
    continue_reading = False

# Hook the SIGINT
signal.signal(signal.SIGINT, end_read)

print "Press Ctrl-C to stop"


def readNfc():
	MIFAREReader = MFRC522.MFRC522()
	
	(status,TagType) = MIFAREReader.MFRC522_Request(MIFAREReader.PICC_REQIDL)
		
	(status,backData) = MIFAREReader.MFRC522_Anticoll()
	if status == MIFAREReader.MI_OK:
		return str(backData[0])+str(backData[1])+str(backData[2])+str(backData[3])+str(backData[4])
	else:
		return "FAILFAILFAIL"

def main():
	global readpath
	global writepath
	while continue_reading:
			rd = open(readpath,'r')
			print "reading..."
			msg = rd.read()
			print "read "+msg
			#print msg[:4]
			rd.close()
			if msg[0] == 'G':
				print "received get"
				uid = readNfc()
				print "uid : "+uid	
				wd = open(writepath,'w')
				wd.write(uid)
				wd.close()
	
	GPIO.cleanup()
main()
