
#include <iostream>
#include <fstream>

#include "ros/ros.h"
#include "std_msgs/String.h"



#include "/home/intel/toibot_ws/devel/include/toi_bot_vision/visionMsgOutput.h"
#include "/home/intel/toibot_ws/devel/include/toi_bot_vision/visionMsgCommand.h"
#include "/home/intel/toibot_ws/devel/include/toi_bot_vision/visionMsgFeatures.h"
#include "/home/intel/toibot_ws/devel/include/toi_bot_vision/visionMsgFeatureOutput.h"
#include "/home/intel/toibot_ws/devel/include/motors/motorsCommand.h"
#include "/home/intel/toibot_ws/devel/include/motors/motorsCommand.h"
#include "/home/intel/toibot_ws/devel/include/toi_bot_speakers/speakersCommand.h"
#include "/home/intel/toibot_ws/devel/include/toi_bot_stt/speechTT.h"





#include "/home/intel/toibot_ws/src/ToiBot1/src/toi_bot_vision/include/toi_bot_vision/visionParams.h"



using namespace std;

enum ActionState { Tracking = 1, Tracking_and_Conversation = 2, RememberMe = 3, EmotionDetection = 4 , Take_a_photo = 5};

struct MotorsMsgOutput{


};

struct SpeakersMsgOutput{

  string response;
  string query;


};

struct VisionMsgOutput{


    visionState visionStateOutput = init ;
    string nameToRemember ="";




};

struct Action{

    ActionState actionState;

    MotorsMsgOutput motorsMsgOutput;

    SpeakersMsgOutput speakersMsgOutput;

    VisionMsgOutput visionMsgOutput;


};

struct VisionInput{

     bool detectFace = false;
     int32_t deltaX = 0;
     int32_t deltaY = 0;
     bool canRecognize = false;
     string name = "";
     string emotion = "";
    int32_t faceArea = 0;


};

struct VoiceInput{

  string query;
  string response;
  string intent;	


};


class robotManagerRos{

public:

    robotManagerRos();

    ~robotManagerRos() {

    }


    void visionCallback(const toi_bot_vision::visionMsgOutput &msg);

    void voiceCallback(const toi_bot_stt::speechTT &msg);

    // void isSpeakingCallback(const std_msgs::String::ConstPtr& msg);

    void initSystem();

    Action takeAction();

    
    void makeTrackingAndConversationAction(const Action& action);

    void makeRememberMeAction(string query);

    void makeEmotionDetectionMeAction();

    void makeRecognitionAction();

    void makeObjectsRecognitionAction();

    void makecCleaningFacesDatabaseAction();

    void makeTakeAPhotoAction();





    void visionFeaturesCallback(const toi_bot_vision::visionMsgFeatureOutput& msg);


    void takeActionOfVisionFeaturesSim();






    

 private:

    ros::NodeHandle node_;

    ros::Rate loop_rate_ = ros::Rate(10);

    string lastStringQueryPublished_;

    ros::Subscriber visonSubInut_;

    VisionInput visionInput_;
    ros::Publisher visionPublisher_;
    ros::Publisher visionFeaturePublisher_;
    ros::Subscriber visionFeatureInput_;




    ros::Publisher motorsPublisher_;
    ros::Publisher speakersPublisher_;


    ros::Subscriber voiceSubInput_;
    VoiceInput  voiceInput_;


    bool init_= false;


    bool canTalkByDialogFlow = true;
    
    bool lastCommandWasEmotion = false;
    bool lastCommandWasRememberMe = false;
    bool lastCommandWasRecognition = false;
    bool lastCommandWasObjectsRecognition = false;
    bool lastCommandWasCleaningFacesDatabase = false;
    bool lastCommandWasTakeAPhoto = false;






    

};
