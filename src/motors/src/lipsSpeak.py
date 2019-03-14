from ohbot import ohbot
from time import sleep
import sys




def speak():

    sentence  = ""

    f = open('/home/gal/toibot_ws/src/ToiBot1/src/motors/lips_speak.txt','r')
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

        for x in range(wordCount ):
            ohbot.move(4,6,1) # TOPLIP
            ohbot.move(5,6,1)
            
            ohbot.wait(0.5)
           
            ohbot.move(4,6,1) # TOPLIP
            ohbot.move(5,6,1)

            ohbot.wait(0.5)

   
       




def main(argv):

    while 1:
        speak()

if __name__ == '__main__':
    main(sys.argv[1:])


