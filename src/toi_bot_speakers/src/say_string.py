#!/home/gal/ToiBotEnv/bin/python

# Loads ohbot python script from here
# /home/gal/ToiBotEnv/lib/python3.6/site-packages/ohbot/ohbot.py
from ohbot import ohbot
from time import sleep
from gtts import gTTS
import subprocess
import os

currentResponse ="hello"
myHome = os.path.expanduser('~')

def play_mp3():
	# ohbot.reset()
	# # 4 TOPLIP    (5= middle // 9= up)
	# ohbot.move(ohbot.TOPLIP,9,1)
	# # 5 BOTTOMLIP (5 = middle // 9= down)
	# ohbot.move(ohbot.BOTTOMLIP,9,1)


	subprocess.Popen(['mpg123', '-q', 'gTTS.mp3']).wait()
	# ohbot.reset()

def get_string_and_say_it():
	pathResponse = myHome + "/toibot_ws/src/ToiBot1/src/toi_bot_speakers/txt_files/response.txt"
	with open(pathResponse, 'r') as myfile:
		dataR = myfile.read()

		if(currentResponse==dataR):
			print("they are the same! ")
		else:
			# print(dataR)
			tts = gTTS(dataR)
			tts.save('gTTS.mp3')
			play_mp3()


			# ohbot.say(dataR)



if __name__ == '__main__':
	get_string_and_say_it()