import sys
import signal
import os
import time
import platform
from myTcp_class import *
from mySerial_class import *

EXIT = 0

message = """
\t/****************************************\\
\t*  _            _     _____ _            *
\t* | |          | |   |  ___| |           *
\t* | |      __ _| |__ | |__ | | ___  ___  *
\t* | |     / _` | '_ \|  __|| |/ _ \/ __| *
\t* | |____| (_| | |_) | |___| |  __/ (__  *
\t* \_____/ \__,_|_.__/\____/|_|\___|\___| *
\t*                                        *
\t*     by David Tavares EPITECH 2014      *
\t*                                        *
\t\****************************************/\n\n"""

def signal_handler(signal, frame):
	print('You pressed Ctrl+C!')
	global EXIT
	EXIT = 1;
	
def initSignal():
	signal.signal(signal.SIGINT, signal_handler)
	print('Press Ctrl+C to quit.')

		
if __name__ == '__main__':
	initSignal()
	ip = "192.168.11.1"
	port = 10002
	com = ""
	verbose = ""

	print(message)
	if(os.name == "nt"):
		defaut_com = "COM3"
	else:
		defaut_com = "/dev/tty.USB0"

	if (int(sys.version_info[0]) < 3):
		try:
			input = raw_input
		except: pass
	print("Platforme:", platform.platform())

	while (len(ip) == 12 and EXIT == 0):
		ip += input('=> Number of Robot (01): ')
	while (len(com) < 4 and EXIT == 0):
		com = input('=> Port COM (' + defaut_com + ') : ')
	while (len(verbose) < 1 and EXIT == 0):
		verbose = input('=> Mode Verbose (Y/N) : ')
	if (verbose == 'Y'):
		isVerbose = True
	else:
		isVerbose = False
		
	if (EXIT == 1):
		sys.exit(0)
	print ("\n/***** Connexion Port COM (" + com + "). *****\\\n")
	serial = mySerial(com, isVerbose)
	if (serial.isConnect()):
		print("\n/***** Connexion Robot in progress .. *****\\\n")
		tcp = myTcp(ip, int(port), isVerbose)
	
	while (serial.isConnect() and tcp.isConnect() and EXIT == 0):
		data = serial.read()
		data2 = tcp.run(data)
		if (data2 == -1):
			EXIT = 1        
		elif (data2):
			serial.write(data2)
		
		time.sleep(200/1000000.0)

	if (os.name == "nt"):
		input('Press enter to quit.')
