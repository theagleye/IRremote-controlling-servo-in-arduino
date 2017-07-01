# IRremote-controlling-servo-in-arduino /d/Mygit/IR_servo/

A simple implementation of IR Remote, a IR reciever and a servo in Ard Uno.
For some reason (I bet if someone with more knowledge about it came by this project and know about the reason could perhaps mention here) Ard IDE threw compiler error while defining the HEX values of the remote, thus I decoded them to DEC and implemented that.

As to functionality, it is a really simple project; button 1 if pressed once, activates the servo to roll from 0 deg to 180 degs and back in a loop. Servo continues to work until the button 0 is pressed which rotates the servo motors back to 0 deg and stops it there. Similarly, if button 2 is pressed, servo rolls from 0-180 degs and back in a loop but with a delay of 4ms, and button 3 does the same with a delay of 6ms.

An LED is also attached which goes on while the servo is working, and off with button 0 while servo stops at 0 deg. 
