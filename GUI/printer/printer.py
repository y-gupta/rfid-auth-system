
# from escpos import *
# import os

# Epson = printer.Usb(0x04b8,0x0202)

# rfPath = "./printer_pipe"
# while (1) :
# 	rp = open(rfPath, 'r')
# 	message = rp.read()
from escpos import *

rfPath = "./printer_pipe"
while (1) :
	Epson.set(align='center', bold=True)
	Epson.image("9795.png")
	rp = open(rfPath, 'r')
	message = rp.read()

# 	Epson.text(message)

# 	Epson.cut()
	Epson.cut()