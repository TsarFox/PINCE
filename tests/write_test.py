from time import sleep
from sys import exit
import os
FILE=open("PINCE-to-Inferior.txt", "w")
FILE.close()
FILE=open("Inferior-to-PINCE.txt", "w")
FILE.close()
FILE=open("status.txt", "w")
FILE.close()
while True:
	status_word="waiting"
	while status_word not in "sync-request-recieve":
		status=open("status.txt", "r")
		status_word=status.read()
		status.close()
		try:
			abort=open("abort.txt", "r")
			abort.close()
			os.remove("abort.txt")
			FILE=open("abort-verify.txt", "w")
			FILE.close()
			exit(0)
		except:
			pass
	status=open("status.txt", "w")
	status.write("sync-request-send")
	status.close()
	FILE=open("PINCE-to-Inferior.txt", "w")
	FILE.close()
	FILE=open("Inferior-to-PINCE.txt", "r")
	readed=FILE.read()
	print(readed)
	FILE.close()