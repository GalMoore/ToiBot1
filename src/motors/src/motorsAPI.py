from ohbot import ohbot
from time import sleep
import sys


currentStateX = 5
currentStateY = 5


def head_tracking_move():

    detlatX = 0
    detlatY = 0
    faceArea = 0
    f = open('/home/intel/toibot_ws/src/ToiBot1/src/motors/headTracking.txt','r')
    out = f.readlines()
    count = 0
    for line in out:
        if count == 0:
            detlatX = int(line)
        if count == 1:
            detlatY = int(line)
        if count == 2:
            faceArea = int(line)
        count = count +1

    print(str(detlatX) +', '+ str(detlatY) )

    f.close()

    global currentStateX
    global currentStateY

    # print('faceArea'+ str(faceArea) )
    if faceArea > 20000:
        threshold = 150
    elif faceArea > 10000:
        threshold = 100
    else:
        threshold = 75


    waiting = 2

    if  detlatX == 100000 :
        # print('init ')
        ohbot.move(1,5,1)
        currentStateX = 5
    elif abs(detlatX) < threshold:
        pass
        # print('dont move ')
    elif  detlatX > threshold :
        # print('my right ' +str(currentStateX) )
        currentStateX = currentStateX + 1
        ohbot.move(1,currentStateX,1)
    elif detlatX < -threshold:
        currentStateX = currentStateX - 1
        ohbot.move(1,currentStateX,1)


    if  detlatY == 100000 or abs(detlatY) < threshold:
        #print('dont move')
        ohbot.move(0,8,1)
        currentStateY = 8
        ohbot.wait(waiting)
    elif  detlatY > threshold :
        currentStateY = currentStateY + 1
        ohbot.move(0,currentStateY,1)
        ohbot.wait(waiting)
    elif detlatY < -threshold:
        currentStateY = currentStateY - 1
        ohbot.move(0,currentStateY,1)
        ohbot.wait(waiting)


    # ohbot.move(3,8,1)
    # ohbot.wait(2)
    # ohbot.move(3,2,1)




def main(argv):
    ohbot.wait(0.5)
    ohbot.reset()
    
    ohbot.move(0,8,1) # y  defualt look up 
    
    ohbot.move(1,5,1) # 
    

    ohbot.move(2,5,1)
    ohbot.move(3,9,1)
    ohbot.move(4,5,1)
    ohbot.move(5,5,1)
    ohbot.move(6,5,1)
    # ohbot.move(2,7,1) # eyes
    ohbot.wait(0.5)

    while 1:
        head_tracking_move()






if __name__ == '__main__':
    main(sys.argv[1:])


