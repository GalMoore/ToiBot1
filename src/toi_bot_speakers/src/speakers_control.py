#!/usr/bin/env python
import rospy
from std_msgs.msg import String
import subprocess
from time import sleep
import os
myHome = os.path.expanduser('~')

from toi_bot_speakers.msg import speakersCommand

# isSpeakrsWorking = False

def callback(data):

        # write data.response received from manager into text file in this path
        pathResponse = myHome + "/toibot_ws/src/ToiBot1/src/toi_bot_speakers/txt_files/response.txt"
        # write data.data to txt file
        write_to_file(pathResponse,(data.response))
        # rospy.loginfo(rospy.get_caller_id() + "I heard %s", data.data)
        python_bin = myHome+"/ToiBotEnv/bin/python"

        # publish that robot is speaking now
        pub.publish("speaking")
        global isSpeakrsWorking
        isSpeakrsWorking = True
        # script say_string checks for new text in response.txt. if found it will say it!
        script_file = myHome+"/toibot_ws/src/ToiBot1/src/toi_bot_speakers/src/say_string.py"
        p = subprocess.Popen([python_bin, script_file])
        p_status = p.wait()

        # publish that robot has finished speaking
        # pub.publish("finished speaking")
        # print("response is: " + str(data.response))

def write_to_file(path,text):
    # only writes to file if string !empty
    if text:
        text_file = open(path, "w")
        text_file.write(text)
        text_file.close()


if __name__ == '__main__':
    rospy.init_node('toi_bot_speakers_node')
    pub = rospy.Publisher('is_robot_speaking_topic', String,queue_size=1)
    rospy.Subscriber("speakers_publisher_command",speakersCommand, callback)
    rospy.spin()
