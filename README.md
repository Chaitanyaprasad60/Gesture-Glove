# Gesture-Glove
This Glove has sensor that capture information of hand Gestures and control a laptop/PC 

Working:
The Glove using Flex sensors for mouse clicks, Accelerometer to know the allignment of hand. 
This is transmitted wirelessly to the laptop, It is received by NRF receiver.
This data is sent to python where the cursor is controlled using PyAutoGuI.

Files:
 1) Final_reciever.ino: This is the Arduino code that is writting in Receiver attached to laptop.
 2) glove2.ino: This collects data from various sensors on glove and transmits neccesary command to laptop.
 3) GUI_Controller: This has two version for MAC and Windows, 
                    The task is to control the cursor using data received from receiver Arduino using PyAutoGUI. 
 4) Snake_glove_code: This Code is used to play Snake-game using Gesture glove( Note: Check out my Snake game repository to know how it works)



