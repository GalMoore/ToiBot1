import sys
sys.path.append('/Users/galmoore/anaconda/envs/ohBotHumanoid')
import ohbot
from time import sleep

# Name	 Range	      Description	    Default
# m	     0-6 (int)	  Motor Number	      -
# pos	 0-10 (int)	  Desired Position    -
# speed	 0-10 (int)	  Motor Speed	      3 (1 is good a steady)

#  EXAMPLE: ohbot.move(motor,postion,speed)

# # m = motor 
# 0 HEADNOD   (1= down // 9=up)
# 1 HEADTURN  (1= MY left // 9=MY right)
# 2 EYETURN   (1= MY left // 9=MY right)
# 3 LIDBLINK  (1= closed // 9= open)
# 4 TOPLIP    (5= middle // 9= up)
# 5 BOTTOMLIP (5 = middle // 9= down)
# 6 EYETILT   (1 = up // 9= down)

# *important to use ohbot.wait() between motor commands for same motor.

# # Reset ohbot
# ohbot.reset()
# ohbot.wait(2)

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

#  3 is a big blink 0 is full blink
def blink(sizeOfBlink):
	ohbot.move(ohbot.LIDBLINK,sizeOfBlink,3)
	ohbot.wait(0.5)
	ohbot.move(ohbot.LIDBLINK,10,3)
	ohbot.wait(0.5)


# this should run in a loop
def waitingPatientlyLeft():
	emotionReset()
	ohbot.move(ohbot.LIDBLINK,4,1)
	#  BREATH
	# 0 HEADNOD   (1= down // 9=up)
	ohbot.move(ohbot.HEADNOD,6,1)
	ohbot.wait(0.5)
	ohbot.move(ohbot.HEADNOD,5,1)
	ohbot.wait(2)
	ohbot.move(ohbot.LIDBLINK,8,1)
	ohbot.wait(1)
	# 3 LIDBLINK  (1= closed // 9= open)
	ohbot.move(ohbot.LIDBLINK,7,1)

	# 2 EYETURN   (1= MY left // 9=MY right)
	ohbot.move(ohbot.EYETURN,3,1)
	ohbot.wait(2)
	# 1 HEADTURN  (1= MY left // 9=MY right)
	ohbot.move(ohbot.HEADTURN,4,1)
	# 2 EYETURN   (1= MY left // 9=MY right)
	ohbot.move(ohbot.EYETURN,5,1)
	ohbot.wait(2)
	#  BREATH
	# 0 HEADNOD   (1= down // 9=up)
	ohbot.move(ohbot.HEADNOD,6,1)
	ohbot.wait(1)

	# 3 LIDBLINK  (1= closed // 9= open)
	ohbot.move(ohbot.LIDBLINK,7,1)
	ohbot.wait(2)
	ohbot.move(ohbot.EYETURN,7,1)
	ohbot.wait(1)
	# 1 HEADTURN  (1= MY left // 9=MY right)
	ohbot.move(ohbot.HEADTURN,5,1)
	ohbot.move(ohbot.EYETURN,5,1)
	ohbot.move(ohbot.HEADNOD,5,1)

def waitingPatientlyRight():
	emotionReset()
	ohbot.wait(1)
	# 3 LIDBLINK  (1= closed // 9= open)
	ohbot.move(ohbot.LIDBLINK,6,1)
	ohbot.wait(2)
	# 0 HEADNOD   (1= down // 9=up)
	ohbot.move(ohbot.HEADNOD,6,1)
	ohbot.wait(2)
	# 2 EYETURN   (1= MY left // 9=MY right)
	ohbot.move(ohbot.EYETURN,6,1)
	ohbot.wait(1)
	ohbot.move(ohbot.EYETURN,5,1)
	ohbot.move(ohbot.HEADNOD,5,1)
	ohbot.wait(2)
	# 2 EYETURN   (1= MY left // 9=MY right)
	ohbot.move(ohbot.EYETURN,6,1)
	ohbot.wait(1)
	ohbot.move(ohbot.EYETURN,7,1)
	ohbot.wait(1)
	ohbot.move(ohbot.EYETURN,5,1)
	# 1 HEADTURN  (1= MY left // 9=MY right)
	ohbot.move(ohbot.HEADTURN,7,1)
	ohbot.wait(1)
	# 3 LIDBLINK  (1= closed // 9= open)
	ohbot.move(ohbot.LIDBLINK,6,1)
	ohbot.wait(1)
	# 1 HEADTURN  (1= MY left // 9=MY right)
	ohbot.move(ohbot.HEADTURN,6,1)
	ohbot.wait(1)
	ohbot.move(ohbot.EYETURN,7,1)
	ohbot.wait(2)
	ohbot.move(ohbot.LIDBLINK,5,1)
	#  BREATH
	# 0 HEADNOD   (1= down // 9=up)
	ohbot.move(ohbot.HEADNOD,6,1)
	ohbot.wait(2)
	# 1 HEADTURN  (1= MY left // 9=MY right)
	ohbot.move(ohbot.HEADTURN,5,1)
	ohbot.move(ohbot.EYETURN,3,1)
	ohbot.move(ohbot.HEADNOD,5,1)

def waitingPatientlyCentre():
	emotionReset()
	ohbot.move(ohbot.LIDBLINK,4,1)
	#  BREATH
	# 0 HEADNOD   (1= down // 9=up)
	ohbot.move(ohbot.HEADNOD,6,1)
	ohbot.wait(0.5)
	ohbot.move(ohbot.HEADNOD,5,1)
	ohbot.wait(2)
	ohbot.move(ohbot.LIDBLINK,8,1)
	ohbot.wait(1)
	# 3 LIDBLINK  (1= closed // 9= open)
	ohbot.move(ohbot.LIDBLINK,7,1)

	# 2 EYETURN   (1= MY left // 9=MY right)
	ohbot.move(ohbot.EYETURN,3,1)
	ohbot.wait(2)
	# 1 HEADTURN  (1= MY left // 9=MY right)
	# ohbot.move(ohbot.HEADTURN,4,1)
	# 2 EYETURN   (1= MY left // 9=MY right)
	ohbot.move(ohbot.EYETURN,5,1)
	ohbot.wait(2)
	#  BREATH
	# 0 HEADNOD   (1= down // 9=up)
	ohbot.move(ohbot.HEADNOD,6,1)
	ohbot.wait(1)

	# 3 LIDBLINK  (1= closed // 9= open)
	ohbot.move(ohbot.LIDBLINK,7,1)
	ohbot.wait(2)
	ohbot.move(ohbot.EYETURN,7,1)
	ohbot.wait(1)
	# 1 HEADTURN  (1= MY left // 9=MY right)
	# ohbot.move(ohbot.HEADTURN,5,1)
	ohbot.move(ohbot.EYETURN,5,1)
	ohbot.move(ohbot.HEADNOD,5,1)
	ohbot.wait(1)
	# 3 LIDBLINK  (1= closed // 9= open)
	ohbot.move(ohbot.LIDBLINK,6,1)
	ohbot.wait(2)
	# 0 HEADNOD   (1= down // 9=up)
	ohbot.move(ohbot.HEADNOD,6,1)
	ohbot.wait(2)
	# 2 EYETURN   (1= MY left // 9=MY right)
	ohbot.move(ohbot.EYETURN,6,1)
	ohbot.wait(1)
	ohbot.move(ohbot.EYETURN,5,1)
	ohbot.move(ohbot.HEADNOD,5,1)
	ohbot.wait(2)
	# 2 EYETURN   (1= MY left // 9=MY right)
	ohbot.move(ohbot.EYETURN,6,1)
	ohbot.wait(1)
	ohbot.move(ohbot.EYETURN,7,1)
	ohbot.wait(1)
	ohbot.move(ohbot.EYETURN,5,1)
	# 1 HEADTURN  (1= MY left // 9=MY right)
	# ohbot.move(ohbot.HEADTURN,7,1)
	ohbot.wait(1)
	# 3 LIDBLINK  (1= closed // 9= open)
	ohbot.move(ohbot.LIDBLINK,6,1)
	ohbot.wait(1)
	# 1 HEADTURN  (1= MY left // 9=MY right)
	# ohbot.move(ohbot.HEADTURN,6,1)
	ohbot.wait(1)
	ohbot.move(ohbot.EYETURN,7,1)
	ohbot.wait(2)
	ohbot.move(ohbot.LIDBLINK,5,1)
	#  BREATH
	# 0 HEADNOD   (1= down // 9=up)
	ohbot.move(ohbot.HEADNOD,6,1)
	ohbot.wait(2)
	# 1 HEADTURN  (1= MY left // 9=MY right)
	# ohbot.move(ohbot.HEADTURN,5,1)
	ohbot.move(ohbot.EYETURN,3,1)
	ohbot.move(ohbot.HEADNOD,5,1)


def waitingPatiently():
	while 1==1:
		waitingPatientlyCentre()
		waitingPatientlyLeft()
		waitingPatientlyRight()
		waitingPatientlyCentre()

def wakingUp():
	emotionReset()
	ohbot.move(ohbot.LIDBLINK,3,1)
	ohbot.wait(2)
	#  BREATH
	# 0 HEADNOD   (1= down // 9=up)
	ohbot.move(ohbot.HEADNOD,3,1)
	ohbot.wait(1)
	ohbot.move(ohbot.HEADNOD,5,1)
	ohbot.wait(0.5)
	# 2 EYETURN   (1= MY left // 9=MY right)
	# 1 HEADTURN  (1= MY left // 9=MY right)
	ohbot.move(ohbot.HEADTURN,2,1)
	ohbot.wait(2)
	ohbot.move(ohbot.HEADTURN,8,1)
	ohbot.wait(1)
	ohbot.move(ohbot.EYETURN,1,1)
	ohbot.wait(0.3)
	ohbot.move(ohbot.EYETURN,9,1)
	ohbot.wait(0.3)
	emotionReset()

	# 2 EYETURN   (1= MY left // 9=MY right)




def worried():

	#  Emotion worried
	# Reset ohbot
	emotionReset()
	# 0 HEADNOD   (1= down // 9=up)
	ohbot.move(ohbot.HEADNOD,7,1)
	# 1 HEADTURN  (1= MY left // 9=MY right)
	ohbot.move(ohbot.HEADTURN,5,1)
	# 2 EYETURN   (1= MY left // 9=MY right)
	ohbot.move(ohbot.EYETURN,5,1)
	# 3 LIDBLINK  (1= closed // 9= open)
	ohbot.move(ohbot.LIDBLINK,10,1)
	# 4 TOPLIP    (5= middle // 9= up)
	ohbot.move(ohbot.TOPLIP,10,1)
	# 5 BOTTOMLIP (5 = middle // 9= down)
	ohbot.move(ohbot.BOTTOMLIP,2,1)
	# 6 EYETILT   (1 = up // 9= down)
	ohbot.move(ohbot.EYETILT,3,1)

	#  RESET EMOTION
	ohbot.wait(0.5)
	emotionReset()


def naughty():
	#  Emotion COY / horny
	# Reset ohbot
	ohbot.reset()
	# 0 HEADNOD   (1= down // 9=up)
	ohbot.move(ohbot.HEADNOD,4,1)
	# 1 HEADTURN  (1= MY left // 9=MY right)
	ohbot.move(ohbot.HEADTURN,5,1)
	# 2 EYETURN   (1= MY left // 9=MY right)
	ohbot.move(ohbot.EYETURN,1,1)
	# 3 LIDBLINK  (1= closed // 9= open)
	ohbot.move(ohbot.LIDBLINK,5,1)
	# 4 TOPLIP    (5= middle // 9= up)
	ohbot.move(ohbot.TOPLIP,1,1)
	# 5 BOTTOMLIP (5 = middle // 9= down)
	ohbot.move(ohbot.BOTTOMLIP,9,1)
	# 6 EYETILT   (1 = up // 9= down)
	ohbot.move(ohbot.EYETILT,3,1)

	#  RESET EMOTION
	ohbot.wait(0.5)
	emotionReset()


def surprised():

	#  Emotion SURPRISED
	# Reset ohbot
	ohbot.reset()
	# 0 HEADNOD   (1= down // 9=up)
	ohbot.move(ohbot.HEADNOD,6,1)
	# 1 HEADTURN  (1= MY left // 9=MY right)
	ohbot.move(ohbot.HEADTURN,5,1)
	# 2 EYETURN   (1= MY left // 9=MY right)
	ohbot.move(ohbot.EYETURN,5,1)
	# 3 LIDBLINK  (1= closed // 9= open)
	ohbot.move(ohbot.LIDBLINK,9,1)
	# 4 TOPLIP    (5= middle // 9= up)
	ohbot.move(ohbot.TOPLIP,9,1)
	# 5 BOTTOMLIP (5 = middle // 9= down)
	ohbot.move(ohbot.BOTTOMLIP,9,1)
	# 6 EYETILT   (1 = down // 9= up)
	ohbot.move(ohbot.EYETILT,9,1)

	#  RESET EMOTION
	ohbot.wait(0.5)
	emotionReset()


def angry():
	#  Emotion ANGRY / CYNICAL
	# Reset ohbot
	ohbot.reset()
	# 0 HEADNOD   (1= down // 9=up)
	ohbot.move(ohbot.HEADNOD,5,1)
	# 1 HEADTURN  (1= MY left // 9=MY right)
	ohbot.move(ohbot.HEADTURN,5,1)
	# 2 EYETURN   (1= MY left // 9=MY right)
	ohbot.move(ohbot.EYETURN,5,1)
	# 3 LIDBLINK  (1= closed // 9= open)
	ohbot.move(ohbot.LIDBLINK,4,1)
	# 4 TOPLIP    (5= middle // 9= up)
	ohbot.move(ohbot.TOPLIP,5,1)
	# 5 BOTTOMLIP (5 = middle // 9= down)
	ohbot.move(ohbot.BOTTOMLIP,5,1)
	# 6 EYETILT   (1 = down // 9= up)
	ohbot.move(ohbot.EYETILT,5,1)

	#  RESET EMOTION
	ohbot.wait(0.5)
	emotionReset()


def sad():

	#  Emotion SAD 
	# Reset ohbot
	ohbot.reset()
	# 0 HEADNOD   (1= down // 9=up)
	ohbot.move(ohbot.HEADNOD,3,1)
	# 1 HEADTURN  (1= MY left // 9=MY right)
	ohbot.move(ohbot.HEADTURN,6,1)
	# 2 EYETURN   (1= MY left // 9=MY right)
	ohbot.move(ohbot.EYETURN,5,1)
	# 3 LIDBLINK  (1= closed // 9= open)
	ohbot.move(ohbot.LIDBLINK,9,1)
	# 4 TOPLIP    (5= middle // 9= up)
	ohbot.move(ohbot.TOPLIP,5,1)
	# 5 BOTTOMLIP (5 = middle // 9= down)
	ohbot.move(ohbot.BOTTOMLIP,5,1)
	# 6 EYETILT   (1 = down // 9= up)
	ohbot.move(ohbot.EYETILT,1,1)

	#  RESET EMOTION
	ohbot.wait(0.5)
	emotionReset()



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





# # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # 

# ohbot.reset()
# blink(3)

waitingPatiently()

# while 1==1:
# 	waitingPatientlyLeft()
# 	waitingPatientlyRight()
# 	waitingPatientlyCentre()





