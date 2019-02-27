#!/usr/bin/env python
import rospy
from std_msgs.msg import String
import subprocess



def callback(data):
    if(data.data):
        # print("data is " + data)
        # print("data.data is " + data.data)
        pathResponse = "/home/gal/toibot_ws/src/ToiBot1/src/text_to_speech/src/txt_files/response.txt"
        # write data.data to txt file
        write_to_file(pathResponse,data.data)
        # rospy.loginfo(rospy.get_caller_id() + "I heard %s", data.data)
        python_bin = "/home/gal/ToiBotEnv/bin/python"
        # publish that robot is speaking now
        pub.publish("speaking!")

        # script say_string checks for new text in response.txt. if found it will say it!
        script_file = "/home/gal/toibot_ws/src/ToiBot1/src/text_to_speech/say_string.py"
        p = subprocess.Popen([python_bin, script_file])
        p_status = p.wait()
        # publish that robot has finished speaking
        pub.publish("finished speaking")


def write_to_file(path,text):
    # only writes to file if string !empty
    if text:
        text_file = open(path, "w")
        text_file.write(text)
        text_file.close()


def listener():

    rospy.init_node('text_to_speech_node')
    #  should receieve response from dialogflow
    rospy.Subscriber("published_topic_from_manager", String, callback)
    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()

if __name__ == '__main__':

    # REWRITE HOW TEXT TO SPEECH WORKS
    # pub = rospy.Publisher('robot_finished_speaking', String,queue_size=10)
    # listener()