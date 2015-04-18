from escpos import *
import os

Epson = printer.Usb(0x04b8,0x0202)
rfPath = "./printer_pipe"

# while (1) :
Epson.set(align='center')
# rp = open(rfPath, 'r')
# message = rp.read()
# Epson.image("9795.png")
Epson.text("Yaay!!\n\nYaay!!")
Epson.cut()
