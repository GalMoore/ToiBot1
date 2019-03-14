from ohbot import ohbot
from time import sleep
import sys


currentStateX = 5
currentStateY = 5


def speak():

    sentence  = ""

    f = open('/home/intel/toibot_ws/src/ToiBot1/src/motors/lips_speak.txt','r')
    out = f.readlines()
    count = 0
    for line in out:
        if count == 0:
            sentence = str(line)

    f.close()

    print(str(sentence))

    words = sentence.split()
    while i < len(words):
        ohbot.move(4,7,1) # TOPLIP
        ohbot.wait(0.5)
        ohbot.move(4,2,1) # TOPLIP




def main(argv):

    while 1:
        speak()

if __name__ == '__main__':
    main(sys.argv[1:])


