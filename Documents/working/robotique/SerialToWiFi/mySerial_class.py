import sys
import serial
import time
import struct

class mySerial:
	'Class for connection Serial'

	buff = ''
	ser = 0

	def __init__(self, pathName, verbose):
		try:
			self.ser = serial.Serial(
				port=pathName, 
				baudrate=9600, 
				timeout=0,
				parity=serial.PARITY_NONE,
				stopbits=serial.STOPBITS_ONE,
				bytesize=serial.EIGHTBITS
				)
			self.isVerbose = verbose
		except BaseException as err :
			print('/!\ **** Error PortCom **** /!\\\n!!! %s !!!' % err)
			self.ser = -1

	def __del__(self):
		if self.ser != -1:
			self.ser.close()

	def isConnect(self):
		if (self.ser != -1):
			return True
		return False

	def read(self):
		if (self.ser == -1):
			return -1
		actualByte = self.ser.read()
		self.buff = ""
		try :
			if actualByte != '' :
				self.buff = actualByte
				if (self.isVerbose):
					print('[PORT COM] Data rcv : %s' % hex(ord(actualByte)))
		except BaseException as Error :
			print('Error = %s' % Error)
			return -1
		return self.buff

	def write(self, data):
		if (self.ser == -1 or isinstance(data, str) == False):
			return -1
		if (self.isVerbose == True):
			print('[PORT COM] Data send : %s' % repr(data))
		self.ser.write(data)

