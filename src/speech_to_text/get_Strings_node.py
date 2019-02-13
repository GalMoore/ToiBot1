#!/usr/bin/env python
# license removed for brevity
import rospy
from std_msgs.msg import String

def get_string_text_results():
    rospy.init_node('gets_strings_node')

    pubQ = rospy.Publisher('query_text_topic', String, queue_size=10)
    pubR = rospy.Publisher('response_text_topic', String, queue_size=10)
    pubI = rospy.Publisher('intent_text_topic', String, queue_size=10)

    rate = rospy.Rate(1) # hz
    while not rospy.is_shutdown():
        # get string from query.txt 
        pathQuery = "/home/gal/toibot_ws/src/ToiBot1/src/speech_to_text/text_files/query.txt"
        with open(pathQuery, 'r') as myfile:
            dataQ = myfile.read()

        pathResponse = "/home/gal/toibot_ws/src/ToiBot1/src/speech_to_text/text_files/response.txt"
        with open(pathResponse, 'r') as myfile:
            dataR = myfile.read()

        pathIntent = "/home/gal/toibot_ws/src/ToiBot1/src/speech_to_text/text_files/intent.txt"
        with open(pathIntent, 'r') as myfile:
            dataI = myfile.read()

            rospy.loginfo(dataQ)
            rospy.loginfo(dataR)
            rospy.loginfo(dataI)
            pubQ.publish(dataQ)
            pubR.publish(dataR)
            pubI.publish(dataI)

            rate.sleep()

if __name__ == '__main__':
    try:
        get_string_text_results()
    except rospy.ROSInterruptException:
        pass