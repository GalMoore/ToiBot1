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
from std_msgs.msg import String

from sys import byteorder
from array import array
from struct import pack
import pyaudio
import wave
import time

THRESHOLD = 500
CHUNK_SIZE = 1024
FORMAT = pyaudio.paInt16
RATE = 16000

# https://stackoverflow.com/questions/892199/detect-record-audio-in-python

def is_silent(snd_data):
    "Returns 'True' if below the 'silent' threshold"
    return max(snd_data) < THRESHOLD

def normalize(snd_data):
    "Average the volume out"
    MAXIMUM = 16384
    times = float(MAXIMUM)/max(abs(i) for i in snd_data)

    r = array('h')
    for i in snd_data:
        r.append(int(i*times))
    return r

def trim(snd_data):
    "Trim the blank spots at the start and end"
    def _trim(snd_data):
        snd_started = False
        r = array('h')

        for i in snd_data:
            if not snd_started and abs(i)>THRESHOLD:
                snd_started = True
                r.append(i)

            elif snd_started:
                r.append(i)
        return r

    # Trim to the left
    snd_data = _trim(snd_data)

    # Trim to the right
    snd_data.reverse()
    snd_data = _trim(snd_data)
    snd_data.reverse()
    return snd_data

def add_silence(snd_data, seconds):
    "Add silence to the start and end of 'snd_data' of length 'seconds' (float)"
    r = array('h', [0 for i in range(int(seconds*RATE))])
    r.extend(snd_data)
    r.extend([0 for i in range(int(seconds*RATE))])
    return r

def record():
    """
    Record a word or words from the microphone and 
    return the data as an array of signed shorts.

    Normalizes the audio, trims silence from the 
    start and end, and pads with 0.5 seconds of 
    blank sound to make sure VLC et al can play 
    it without getting chopped off.
    """
    p = pyaudio.PyAudio()
    stream = p.open(format=FORMAT, channels=1, rate=RATE,
        input=True, output=True,
        frames_per_buffer=CHUNK_SIZE)

    num_silent = 0
    snd_started = False

    r = array('h')

    while 1:
        # little endian, signed short
        snd_data = array('h', stream.read(CHUNK_SIZE))
        if byteorder == 'big':
            snd_data.byteswap()
        r.extend(snd_data)

        silent = is_silent(snd_data)

        if silent and snd_started:
            num_silent += 1
        elif not silent and not snd_started:
            snd_started = True

        if snd_started and num_silent > 30:
            break

    sample_width = p.get_sample_size(FORMAT)
    stream.stop_stream()
    stream.close()
    p.terminate()

    r = normalize(r)
    r = trim(r)
    # r = add_silence(r, 0.1)
    return sample_width, r

# RECORDS 'filename.wav '
def record_to_file(path):
    "Records from the microphone and outputs the resulting data to 'path'"
    sample_width, data = record()
    data = pack('<' + ('h'*len(data)), *data)

    wf = wave.open(path, 'wb')
    wf.setnchannels(1)
    wf.setsampwidth(sample_width)
    wf.setframerate(RATE)
    wf.writeframes(data)
    wf.close()

def google():
    ''' PYTHON 3 CODE THAT CONVERTS WAV TO STRING AND QUERIES 
    DIALOGFLOW FOR INTENT & RESULT WHICH ARE PRINTED INTO TXT FILES in scropt dialogflowAPI'''
    python_bin = "/home/gal/ToiBotEnv/bin/python"
    # # path to the script that must run under the virtualenv
    script_file = "/home/gal/toibot_ws/src/ToiBot1/src/speech_to_text/dialogflowAPI.py"
    # Query Dialogflow, get string and response and write to txt file
    p = subprocess.Popen([python_bin, script_file])
    p_status = p.wait()
    # p.kill()

def recordSentenceToWav():
            # print("")           
            # print("START SPEAKING")
            # print("")
            # # play_wav("start")
            record_to_file('/home/gal/toibot_ws/src/ToiBot1/src/speech_to_text/speech_wavs/filename.wav')
            # print("")
            # print("SENDING WAV TO INTERNETS!")
            # print("")
            # play_wav("end")

def send_Wav_to_google_get_response_txt_file_and_publish():

            google()
            print("")
            # get string from text file and publish it
            pathResponse = "/home/gal/toibot_ws/src/ToiBot1/src/speech_to_text/text_files/query.txt"
            with open(pathResponse, 'r') as myfile:
                dataR = myfile.read()
                print dataR
            pub.publish(dataR)
            # delete text file (by opening it in write mode)
            open(pathResponse, 'w').close()

if __name__ == '__main__':

        rospy.init_node('speech_to_text_node')
        pub = rospy.Publisher('what_robot_heard_last', String,queue_size=10)

        # record sentences as they are spoken.
        while(1):
            recordSentenceToWav()
            start = time.time()
            send_Wav_to_google_get_response_txt_file_and_publish()
            end = time.time()
            print("took this long to get response from google and publish to topic:")
            print(end-start)