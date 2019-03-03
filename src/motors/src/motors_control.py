#!/usr/bin/env python
import rospy
from std_msgs.msg import String
import subprocess
from time import sleep
import os

from motors.msg import motorsCommand


myHome = os.path.expanduser('~')


def tracking_move(deltaX, deltaY):

    delatXstr = str(deltaX)+" "
    delatYstr = str(deltaY)
    commad = "python3" + myHome + "/toibot_ws/src/ToiBot1/src/motors/src/motorsAPI.py "
    fullCommand =    commad + delatXstr + delatYstr
    #print(fullCommand)
    os.system(fullCommand)

#    python_bin = "/home/toilab/ToiBotEnv/bin/python"

#    script_file = "/home/toilab/toibot_ws/src/ToiBot1/src/motors/src/motorsAPI.py"

#    p = subprocess.Popen([python_bin, script_file])
#    p_status = p.wait()
#    p.kill()

#    subprocess.call(args, shell=True)



def callback(data):

    #rospy.loginfo("%d ,  %s " % (data.deltaX, data.sentence))

    deltaX = int(data.deltaX)
    deltaY = int(data.deltaY)
    tracking_move(deltaX,deltaY)


    
def motors():

    rospy.Subscriber("motors_publisher_command",motorsCommand, callback)

    rospy.spin()


if __name__ == '__main__':
    rospy.init_node('motors_node')
    motors()
