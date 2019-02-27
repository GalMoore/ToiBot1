#!/usr/bin/env python
import rospy
from std_msgs.msg import String
import subprocess

currentData = "smile"

def callback(data):
    rospy.loginfo(rospy.get_caller_id() + "vI heard %s", data.data)

    if(currentData==data.data):
        print("they are the same! ")
    else:
    # print(dataR)
    # ohbot.say(dataR)

        if(data.data=="smile"):
            print("wow it works!")
            python_bin = "/home/gal/ToiBotEnv/bin/python"
            # # path to the script that must run under the virtualenv
            script_file = "/home/gal/toibot_ws/src/ToiBot1/src/motors/src/facial_expressions.py"
            p = subprocess.Popen([python_bin, script_file])
            p_status = p.wait()
            # p.kill()
            # currentData = data.data

def motors():
    rospy.init_node('motors_node')

    python_bin = "/home/gal/ToiBotEnv/bin/python"
    # # path to the script that must run under the virtualenv
    script_file = "/home/gal/toibot_ws/src/ToiBot1/src/motors/src/waiting_motors.py"
    p1 = subprocess.Popen([python_bin, script_file])
    # p1_status = p.wait()

    rospy.Subscriber("query_text_topic", String, callback)

    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()

if __name__ == '__main__':
    motors()