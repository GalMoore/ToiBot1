#!/home/gal/ToiBotEnv/bin/python
from ohbot import ohbot
from time import sleep

currentR ="hello"

def get_string_and_say_it():
	pathResponse = "/home/gal/toibot_ws/src/ToiBot1/src/text_to_speech/src/txt_files/response.txt"
	with open(pathResponse, 'r') as myfile:
		dataR = myfile.read()

		if(currentR==dataR):
			print("they are the same! ")
		else:
			print(dataR)
			ohbot.say(dataR)


            # rate.sleep()

if __name__ == '__main__':
    try:
        get_string_and_say_it()
    except rospy.ROSInterruptException:
        pass