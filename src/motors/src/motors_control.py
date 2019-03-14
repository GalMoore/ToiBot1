#!/usr/bin/env python
import rospy
from std_msgs.msg import String
import subprocess
from time import sleep
import os


from motors.msg import motorsCommand




def tracking_move(deltaX, deltaY, faceArea):

        f= open('/home/gal/toibot_ws/src/ToiBot1/src/motors/headTracking.txt',"w+")

        f.write(str(deltaX)+'\n')
        f.write(str(deltaY)+'\n')
        f.write(str(faceArea))
        f.close()

        #print(str(deltaX) +','+str(deltaY)+ ', '+ str(faceArea) )

def lips_speak(setnence):

        f= open('/home/gal/toibot_ws/src/ToiBot1/src/motors/lips_speak.txt',"w+")

        


        f.write(str(setnence)+'\n')

        f.close()




def callback(data):

    #rospy.loginfo("%d ,  %s " % (data.deltaX, data.sentence))

    deltaX = int(data.deltaX)
    deltaY = int(data.deltaY)
    faceArea = int(data.faceArea)
    setnence = str(data.setnence)


    f = open('/home/gal/toibot_ws/src/ToiBot1/src/motors/lips_speak.txt',"w+")

        


    f.write('')

    f.close()

   

        


    tracking_move(deltaX,deltaY, faceArea)

    if setnence != '':
        lips_speak(setnence)
        print('setnence ' + setnence)









    
def motors():

    rospy.Subscriber("motors_publisher_command",motorsCommand, callback)

    rospy.spin()


if __name__ == '__main__':
    rospy.init_node('motors_node')
    motors()
