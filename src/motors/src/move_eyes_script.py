from ohbot import ohbot
from time import sleep
import sys




def moves_eyes():
    ohbot.move(2,1,5)
    ohbot.wait(1)
    ohbot.move(2,10,5)
    ohbot.wait(1)
    ohbot.move(2,5,5)
    ohbot.wait(1)

            
         




def main(argv):
    moves_eyes()


if __name__ == '__main__':
    main(sys.argv[1:])


