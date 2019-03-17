from ohbot import ohbot
from time import sleep
import sys




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

    if sentence != '':
        words = sentence.split()

        print(words)

        wordCount = len(words)
        print(str(wordCount))
        for x in range( int(wordCount )  ):
            ohbot.move(4,7,1) # TOPLIP
            ohbot.wait(0.5)

            ohbot.move(5,7,1)

            ohbot.wait(0.5)

            ohbot.move(4,5,1)

            ohbot.wait(0.5)

            ohbot.move(5,5,1)

    else:
       ohbot.move(4,5,1) # TOPLIP
       ohbot.wait(0.5)
       ohbot.move(5,5,1)
       ohbot.wait(0.5)  
            
         




def main(argv):
    ohbot.move(4,5,1) # TOPLIP
    ohbot.wait(0.5)
    ohbot.move(5,5,1)
    ohbot.wait(0.5)

    while 1:
        speak()

if __name__ == '__main__':
    main(sys.argv[1:])


