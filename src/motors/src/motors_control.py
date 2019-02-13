#!/usr/bin/env python
import rospy
from std_msgs.msg import String
import subprocess

def callback(data):
    rospy.loginfo(rospy.get_caller_id() + "vI heard %s", data.data)
    if(data.data=="smile"):
        print("wow it works!")

        python_bin = "/home/gal/ToiBotEnv/bin/python"
        # # path to the script that must run under the virtualenv
        script_file = "/home/gal/toibot_ws/src/ToiBot1/src/motors/src/facial_expressions.py"
        p = subprocess.Popen([python_bin, script_file])
        p_status = p.wait()
        # p.kill()

    
def motors():

    # In ROS, nodes are uniquely named. If two nodes with the same
    # name are launched, the previous one is kicked off. The
    # anonymous=True flag means that rospy will choose a unique
    # name for our 'listener' node so that multiple listeners can
    # run simultaneously.
    rospy.init_node('motors_node')

    rospy.Subscriber("published_topic_from_manager", String, callback)

    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()

if __name__ == '__main__':
    motors()