#!/usr/bin/env python
# Software License Agreement (BSD License)

'''
SPEECH TO TEXT NODE
This node constantly listens for speech above THRESHOLD
if found, waits for end of sentence, and send resulting wav file to google to get:
A query in text
B intent
C response
'''

import subprocess
import rospy
import sys
from sys import byteorder
from array import array
from struct import pack
import pyaudio
import wave
import time
from std_msgs.msg import String
from toi_bot_stt.msg import speechTT
import os
import pyaudio
import wave
from array import array
import time

myHome = os.path.expanduser('~')

# RATE = 16000
isRobotSpeaking = False
message = speechTT()
pub =rospy.Publisher('/stt_topic', speechTT, queue_size=1)
FORMAT=pyaudio.paInt16
CHANNELS=1
RATE=16000 # takes a few hundread samples per second
CHUNK=1024
minimum_tresh_to_trigger_ears=100
FILE_NAME= myHome + '/toibot_ws/src/ToiBot1/src/toi_bot_stt/speech_wavs/filename.wav'
audio=pyaudio.PyAudio() #instantiate the pyaudio
frames=[] #starting recording into this array
has_reached_first_threshold = False
i = 0
tic = time.time()
#recording prerequisites
stream=audio.open(format=FORMAT,channels=CHANNELS, 
                  rate=RATE,
                  input=True,
                  frames_per_buffer=CHUNK)

def google():
    ''' PYTHON 3 CODE THAT CONVERTS WAV TO STRING AND QUERIES 
    DIALOGFLOW FOR INTENT & RESULT WHICH ARE PRINTED INTO TXT FILES in scropt dialogflowAPI'''
    python_bin = myHome + "/ToiBotEnv/bin/python"
    # # path to the script that must run under the virtualenv
    script_file = myHome + "/toibot_ws/src/ToiBot1/src/toi_bot_stt/src/dialogflowAPI.py"
    # Query Dialogflow, get string and response and write to txt file
    p = subprocess.Popen([python_bin, script_file])
    p_status = p.wait()
    # p.kill()

def finished_speaking():
    print("finished speaking")
    #end of recording
    stream.stop_stream()
    print("stopped stream")
    stream.close()
    print("closed stream")
    audio.terminate()
    print("audio terminated")
    #writing to file
    wavfile=wave.open(FILE_NAME,'wb')
    print("opened wavfile")
    wavfile.setnchannels(CHANNELS)
    print("set channels")
    wavfile.setsampwidth(audio.get_sample_size(FORMAT))
    print("setswampwidth")
    wavfile.setframerate(RATE)
    print("setframerate")
    wavfile.writeframes(b''.join(frames))#append frames recorded to file
    print("write frames")
    wavfile.close()
    print("closed wavfile")
    return

def detect_and_record():

    global has_reached_first_threshold
    global i 
    global minimum_tresh_to_trigger_ears

    while(True):
        data=stream.read(CHUNK)
        data_chunk=array('h',data) #data_chunk is an array of 2048 numbers
        vol=max(data_chunk)

        # Has not reached first threshold yet
        if(vol<minimum_tresh_to_trigger_ears and has_reached_first_threshold==False):
            print("not recording yet - less than vol minimum_tresh_to_trigger_ears!")
        
        # reached threshold first time
        if(vol>minimum_tresh_to_trigger_ears and has_reached_first_threshold==False):
            print("something said - past first thresh - started recording")
            # set boolean to True for i=84 counts
            has_reached_first_threshold = True
            frames.append(data) 

        if(vol<minimum_tresh_to_trigger_ears and has_reached_first_threshold==True):
            # allows two second beneath threshold
            frames.append(data) 
            if(i==30):
                # and then finishes recording
                finished_speaking()
                return

        if(vol>minimum_tresh_to_trigger_ears and has_reached_first_threshold==True):
            frames.append(data) 
            # reset counter
            i = 0 

        i=i+1

def recordSentenceToWav():
    detect_and_record()

def send_Wav_to_google_get_response_txt_file_and_publish():

            google()

            # get string from text file and publish it
            pathQuery = myHome + "/toibot_ws/src/ToiBot1/src/toi_bot_stt/text_files/query.txt"
            with open(pathQuery, 'r') as myfile:
                dataQ = myfile.read()
            message.query = dataQ

            pathResponse = myHome + "/toibot_ws/src/ToiBot1/src/toi_bot_stt/text_files/response.txt"
            with open(pathResponse, 'r') as myfile:
                dataR = myfile.read()
            message.response = dataR

             # ADD INTENT TO MESSAGE
            pathIntent = myHome + "/toibot_ws/src/ToiBot1/src/toi_bot_stt/text_files/intent.txt"
            with open(pathIntent, 'r') as myfile:
                dataI = myfile.read()
            message.intent = dataI

            pub.publish(message)
            # delete text files (by opening them in write mode)
            open(pathQuery, 'w').close()
            open(pathResponse, 'w').close()
            open(pathIntent, 'w').close()


isRobotSpeaking 

def callback(data):

    global isRobotSpeaking

    if str(data.data) == "speaking":
        isRobotSpeaking = True
        print('speeeeeeking ')
        print('speeeeeeking ')
        print('speeeeeeking ')
        print('speeeeeeking ')
    else:
         isRobotSpeaking = False
         print('nooooooott   speeeeeeking ')
         print('nooooooott   speeeeeeking ')
         print('nooooooott   speeeeeeking ')


if __name__ == '__main__':
    rospy.init_node('toi_bot_stt_node')

    # while
    if isRobotSpeaking == True:
        print('not record')
    else:
       recordSentenceToWav()
       start = time.time()
       send_Wav_to_google_get_response_txt_file_and_publish()
       end = time.time()
       print("took this long to get response from google and publish to topic:")
       print(end-start)

    # recordSentenceToWav()
    # send_Wav_to_google_get_response_txt_file_and_publish()

    # rospy.Subscriber("/is_robot_speaking_topic", String, callback)

    # while(1):

    #     print(str(isRobotSpeaking))
    #     if isRobotSpeaking == True:
    #         print('not record')
    #     else:
    #        recordSentenceToWav()
    #        start = time.time()
    #        send_Wav_to_google_get_response_txt_file_and_publish()
    #        end = time.time()
    #        print("took this long to get response from google and publish to topic:")
    #        print(end-start)

