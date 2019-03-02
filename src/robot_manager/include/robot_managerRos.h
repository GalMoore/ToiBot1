#include "ros/ros.h"
#include "std_msgs/String.h"


#include "/home/gal/toibot_ws/devel/include/toi_bot_vision/visionMsgOutput.h"
#include "/home/gal/toibot_ws/devel/include/toi_bot_vision/visionMsgCommand.h"

#include "/home/gal/toibot_ws/devel/include/motors/motorsCommand.h"



#include "/home/gal/toibot_ws/src/ToiBot1/src/toi_bot_vision/include/toi_bot_vision/visionParams.h"





using namespace std;

enum ActionState { Tracking = 1, Tracking_and_Conversation = 2, RememberMe = 3, EmotionDetection = 4 };

struct MotorsMsgOutput{



};

struct SpeakersMsgOutput{



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
 int deltaX = 0;
 int deltaY = 0;
 bool canRecognize = false;
 string name = "";
 string emotion = "";


};

struct VoiceInput{

  string inputText ="";	


};


class robotManagerRos{

public:

    robotManagerRos();

    ~robotManagerRos() {

    }


    void visionCallback(const toi_bot_vision::visionMsgOutput &msg);

    void voiceCallback(std_msgs::String input);

    void initSystem();


    Action takeAction();

    void makeTrackingAction(const Action& Action);
    void makeRememberMeAction(const Action& Action);
    void makeEmotionDetectionMeAction(const Action& Action);



    

 private:

    ros::NodeHandle node_;

    ros::Rate loop_rate_ = ros::Rate(10);


    ros::Subscriber visonSubInut_;
    VisionInput visionInput_;
    ros::Publisher visionPublisher_;


    ros::Publisher motorsPublisher_;


    ros::Subscriber voiceSubInput_;
    VoiceInput  voiceInput_;

    bool init_= false;


    

};
