from ohbot import ohbot
from time import sleep
import sys



def tracking_move(deltaX,deltaY):

    ohbot.move(str(5),str(5),5)

    #ohbot.move(str(deltaX),str(deltaY),5)
    #print (deltaX + ' ' + deltaY)


def main(argv):
    deltaX = argv[0]
    deltaY = argv[1]
    tracking_move(deltaX, deltaY)

if __name__ == '__main__':
    main(sys.argv[1:])


