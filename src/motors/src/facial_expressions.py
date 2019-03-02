from ohbot import ohbot
from time import sleep

#  CALL THIS SCRIPT FROM "call_check_motors"
# test motors script for experiementation only

def testing_move():
	# # Move all motors
	for y in range(8):
	    for x in range(10):
	        ohbot.move(y,x,5)
	        ohbot.wait(0.4)
	        ohbot.reset()

def emotionReset():
    ohbot.wait(0.5)
    ohbot.reset()
    ohbot.move(0,5,1)
    ohbot.move(1,5,1)
    ohbot.move(2,5,1)
    ohbot.move(3,9,1)
    ohbot.move(4,5,1)
    ohbot.move(5,5,1)
    ohbot.move(6,5,1)

def happy():
	#  Emotion HAPPY 
	# Reset ohbot
	ohbot.reset()
	# 0 HEADNOD   (1= down // 9=up)
	ohbot.move(ohbot.HEADNOD,5,1)
	# 1 HEADTURN  (1= MY left // 9=MY right)
	ohbot.move(ohbot.HEADTURN,5,1)
	# 2 EYETURN   (1= MY left // 9=MY right)
	ohbot.move(ohbot.EYETURN,5,1)
	# 3 LIDBLINK  (1= closed // 9= open)
	ohbot.move(ohbot.LIDBLINK,9,1)
	# 4 TOPLIP    (5= middle // 9= up)
	ohbot.move(ohbot.TOPLIP,2,1)
	# 5 BOTTOMLIP (5 = middle // 9= down)
	ohbot.move(ohbot.BOTTOMLIP,9,1)
	# 6 EYETILT   (1 = down // 9= up)
	ohbot.move(ohbot.EYETILT,5,1)

	#  RESET EMOTION
	ohbot.wait(0.5)
	emotionReset()

import sys

print(sys.argv)
happy()
# testing_move()




