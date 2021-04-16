import time
import serial
import struct
import pyautogui
 
ser = serial.Serial(port='COM3', baudrate=9600)
 
while True:
 value = ser.read(1)
 print(value)

 if(value==b'a'):
      pyautogui.moveRel(15,0)
 elif(value==b'b'):
     pyautogui.moveRel(10,0)
 elif(value==b'c'):
     pyautogui.moveRel(-15,0)
 elif(value==b'd'):
     pyautogui.moveRel(-10,0)
 elif(value==b'e'):
     pyautogui.moveRel(0,15)
 elif(value==b'f'):
     pyautogui.moveRel(0,9)
 elif(value==b'h'):
     pyautogui.moveRel(0,-9)
 elif(value==b'g'):
     pyautogui.moveRel(0,-15)
 elif(value==b'l'):
     pyautogui.click()
 elif(value==b'r'):
     pyautogui.click(button='right')
 value=b'z';

 
 
     
 
 #k=int(value[0:2])
 #print(k)
 #pyautogui.moveRel(k)
 
 time.sleep(0.05)
