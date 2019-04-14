
#include "/home/intel/toibot_ws/src/ToiBot1/src/toi_bot_vision/include/toi_bot_vision/visionRos.h"



using namespace dlib;
using namespace std;


bool lastStateWasPhoto = false;


void visionRos::visionCallbackCommand(const toi_bot_vision::visionMsgCommand& msg){

    state_ = static_cast<visionState>(msg.visionStateCommand);

    name_ =  msg.personName;

}

void visionRos::visionCallbackFeature(const toi_bot_vision::visionMsgFeatures& msg){

    ///emotion
    if ( msg.feature.find("emotion") != string::npos    ){
        
        VisionOutputForManager visionMsgOutputEmotion = personManager_.detectEmotion(state_, frame);

        cv::putText(frame,visionMsgOutputEmotion.emotion,
                    cv::Point(frame.rows/2,frame.cols/2),1, 3, cv::Scalar(0,255,0),3,8);
        imshow("frame",frame);
        waitKey(1);
        
        toi_bot_vision::visionMsgFeatureOutput m;
        m.featureAnswer = visionMsgOutputEmotion.emotion;
        visionFeaturePublisherOutput_.publish(m);
        ros::spinOnce();


    }
    /// remember me 
    else if ( msg.feature.find("remember me") != string::npos    ){
        
        std::vector<string> sentence = foldersManagment_.explode(msg.feature,' ');
        string name = sentence[sentence.size()- 1];

        personManager_.rememberMe(state_,name, frame);


        toi_bot_vision::visionMsgFeatureOutput m;
        m.featureAnswer =  "ok, it's done " + name ;
        visionFeaturePublisherOutput_.publish(m);
        ros::spinOnce();


    }
    /// faces recognition 
    else if ( msg.feature.find("recognition") != string::npos    ){
        

        VisionOutputForManager visionOutputRecognize = personManager_.recognize(state_,frame);
        string name = visionOutputRecognize.name;


        toi_bot_vision::visionMsgFeatureOutput m;
        m.featureAnswer = "I think that your name is "+ name;
        if (name == ""){
          m.featureAnswer = "I dont know you yet";
 
        }
        visionFeaturePublisherOutput_.publish(m);
        ros::spinOnce();


    } 
     /// objetcs recognition 
    else if ( msg.feature.find("objects") != string::npos    ){
        

        string objectsSentence = personManager_.objectsDetection(state_,frame);

        toi_bot_vision::visionMsgFeatureOutput m;
        m.featureAnswer = objectsSentence;
        
        visionFeaturePublisherOutput_.publish(m);
        ros::spinOnce();


    }  /// cleaning faces database 
    else if ( msg.feature.find("remove database") != string::npos    ){
      
        personManager_.removeFacesDatabase();

        toi_bot_vision::visionMsgFeatureOutput m;
        m.featureAnswer = "ok, removing faces database";
        
        visionFeaturePublisherOutput_.publish(m);
        ros::spinOnce();


    }
    /// tkake a photo
    else if ( msg.feature.find("take photo") != string::npos &&
         lastStateWasPhoto == false ){
      
        personManager_.takePhoto(state_,frame);

        toi_bot_vision::visionMsgFeatureOutput m;
        m.featureAnswer = "ok, don't forget to smile";
        lastStateWasPhoto = true;

        visionFeaturePublisherOutput_.publish(m);
        ros::spinOnce();


    }
    

    
}

void visionRos::convertVisionStructToMsg(toi_bot_vision::visionMsgOutput& m, VisionOutputForManager visionOutput){

    m.canRecognize = visionOutput.canRecognize;
    m.deltaX = visionOutput.deltaX ;
    m.deltaY = visionOutput.deltaY;
    m.detectFace = visionOutput.detectFace;
    m.emotion = visionOutput.emotion;
    m.name =  visionOutput.name;

}

void visionRos::initSystem(){

    if( init_ == false ){

        visionPublisher_ = node_.advertise<toi_bot_vision::visionMsgOutput>(
                "vision_publisher_output", 1, true);

        visonSubCommand_ = node_.subscribe( "vision_publisher_command", 1,  &visionRos::visionCallbackCommand, this);

        visonSubFeature_ = node_.subscribe( "vision_publisher_features", 1,  &visionRos::visionCallbackFeature, this);

        visionFeaturePublisherOutput_ = node_.advertise<toi_bot_vision::visionMsgFeatureOutput>(
                "vision_publisher_features_output", 1, true);

        init_ = true;

    }
}

visionRos::visionRos(){


    initSystem();

    while(ros::ok()){


        cap >> frame;

        if( state_ == init){
            state_ = tracking;
        }

        if( state_ == tracking ){

            lastStateWasPhoto = false;
            
            VisionOutputForManager visionOutput = personManager_.track(state_,frame);

            toi_bot_vision::visionMsgOutput m;
            convertVisionStructToMsg(m,visionOutput);
            
            visionPublisher_.publish(m);

            state_ = tracking;

        }        

        ros::spinOnce();

    }



}

