
# from escpos import *
# import os

# Epson = printer.Usb(0x04b8,0x0202)

# rfPath = "./printer_pipe"
# while (1) :
# 	rp = open(rfPath, 'r')
# 	message = rp.read()

# 	rp.close()

# 	Epson.text(message)

# 	Epson.cut()
from escpos import *

Epson = printer.Usb(0x04b8,0x0202)
Epson.text("Rishit\n")
Epson.cut()

# with EscposIO(printer.Usb(0x04b8,0x0202)) as p:
#     p.set(font='a', codepage='cp1251', size='normal', align='center', bold=True)
#     p.printer.set(align='center')
#     p.cut()
    # p.printer.image('logo.gif')
    # p.writelines('Big line\n', font='b')
    # p.writelines(u'BIG TEXT', size='2x')
