
#include "/home/intel/toibot_ws/src/ToiBot1/src/robot_manager/include/robot_managerRos.h"

#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>


using namespace std;




void robotManagerRos::visionCallback(const toi_bot_vision::visionMsgOutput& msg){


    visionInput_.detectFace = msg.detectFace;
    visionInput_.deltaX = msg.deltaX;
    visionInput_.deltaY = msg.deltaY;
    visionInput_.canRecognize = msg.canRecognize;
    visionInput_.name = msg.name;
    visionInput_.emotion = msg.emotion;
    visionInput_.faceArea = msg.faceArea;

}

void robotManagerRos::voiceCallback(const toi_bot_stt::speechTT &msg){

  voiceInput_.query = msg.query;
  voiceInput_.response = msg.response;
  voiceInput_.intent = msg.intent;

  cout<<" from voice callback "<<voiceInput_.query<<endl;



  // cout<<" voiceInput_.response "<<voiceInput_.response<<endl;

}

void robotManagerRos::initSystem(){

    //init once
    if(init_ == false){

        visonSubInut_ =    node_.subscribe("vision_publisher_output", 1,  &robotManagerRos::visionCallback, this);

        voiceSubInput_ =    node_.subscribe("/stt_topic", 1, &robotManagerRos::voiceCallback, this);

        // checkIfRobotSpeaking_ =  node_.subscribe("/is_robot_speaking_topic", 1, &robotManagerRos::isSpeakingCallback, this);        

        visionPublisher_ = node_.advertise<toi_bot_vision::visionMsgCommand>(
                    "vision_publisher_command", 1, true);

        ///motors
        motorsPublisher_ = node_.advertise<motors::motorsCommand>(
                    "motors_publisher_command", 1, true);

        ///speakers
        speakersPublisher_ = node_.advertise<toi_bot_speakers::speakersCommand>(
                    "speakers_publisher_command", 1, true);

        init_ = true;
    }
}

Action robotManagerRos::takeAction(){

    
    if ( voiceInput_.query == "take a photo"){
         cout<<" want to take a pictures"<<endl;
         Action action;
         action.actionState = Take_a_photo;
         action.visionMsgOutput.visionStateOutput = takePhoto;

         return action;

    } else{

        Action action;
        // give it state Tracking and conversation if ... tbc
        action.actionState = Tracking_and_Conversation;

        // give the visionMsg command "tracking " so it tracks
        action.visionMsgOutput.visionStateOutput = tracking;

        /// speakers    
        // give the speakers a response to be said
        action.speakersMsgOutput.response = voiceInput_.response;
        action.speakersMsgOutput.query = voiceInput_.query;

        return action;


    }

   


}


void robotManagerRos::makeTrackingAction(const Action& action){


    ///vision part
    toi_bot_vision::visionMsgCommand visionMsg;
    visionMsg.visionStateCommand = visionState::tracking;
    visionMsg.personName = "unknown";
    visionPublisher_.publish(visionMsg);

    ///motors part
    motors::motorsCommand motorsMsg;
   

     motorsMsg.deltaX =  visionInput_.deltaX;
     motorsMsg.deltaY =  visionInput_.deltaY;
     motorsMsg.faceArea = visionInput_.faceArea;

     // debug only
     // cout<<(int) motorsMsg.deltaX <<", "<<(int)motorsMsg.deltaY<<", "<<(int)motorsMsg.faceArea<<endl;

     motorsPublisher_.publish(motorsMsg);

     ros::spinOnce();
     loop_rate_.sleep();

    



}

void robotManagerRos::makeTrackingAndConversationAction(const Action& action){

  //within the robotmanagerROS while loop, when the actionState points to this 
  //state, the code below will run in a loop until another state is called.



    ///vision part
    toi_bot_vision::visionMsgCommand visionMsg;
    visionMsg.visionStateCommand = visionState::tracking;
    visionMsg.personName = "unknown";
    visionPublisher_.publish(visionMsg);

    ///motors part
    motors::motorsCommand motorsMsg;  

     motorsMsg.deltaX =  visionInput_.deltaX;
     motorsMsg.deltaY =  visionInput_.deltaY;
     motorsMsg.faceArea = visionInput_.faceArea;
     motorsMsg.faceArea = visionInput_.faceArea;
     motorsMsg.setnence = "";

     ///speakers part

     toi_bot_speakers::speakersCommand speakersMsg;
     speakersMsg.response =   action.speakersMsgOutput.response;
     //debug only
     // cout<<"speakersMsg.response: " << speakersMsg.response << endl;


     //If the message received from Dialogflow is not empty
     if( action.speakersMsgOutput.response != ""){
      // and the query heard from user is new (not same as last query)
      if( action.speakersMsgOutput.query!= lastStringQueryPublished_){
        // publish the response from dialogflow to speakers to be spoken! 
        speakersPublisher_.publish(speakersMsg);
        lastStringQueryPublished_= action.speakersMsgOutput.query;
        // cout<<lastStringQueryPublished_<<endl;

        motorsMsg.setnence = action.speakersMsgOutput.response;

      }
    }

     motorsPublisher_.publish(motorsMsg);

     ros::spinOnce();
     loop_rate_.sleep();


}

void robotManagerRos::makeRememberMeAction(const Action& action){

     ///vision part
    toi_bot_vision::visionMsgCommand m;
    m.visionStateCommand = visionState::memorization;
    m.personName = action.visionMsgOutput.nameToRemember;
    visionPublisher_.publish(m);

    ros::spinOnce();
    loop_rate_.sleep();

}

void robotManagerRos::makeEmotionDetectionMeAction(const Action& action){

    ///vision part
    toi_bot_vision::visionMsgCommand m;
    m.visionStateCommand = visionState::emotionRecognition;
    m.personName = "";
    visionPublisher_.publish(m);

    ros::spinOnce();
    loop_rate_.sleep();

}

void robotManagerRos::takeAPhotoAction(const Action& action){

    ///vision part
    toi_bot_vision::visionMsgCommand visionMsg;
    visionMsg.visionStateCommand = takePhoto;
    visionMsg.personName = "unknown";
    visionPublisher_.publish(visionMsg);

   



}



robotManagerRos::robotManagerRos(){

  //  loop through the while. Each time query takeAction()
  // which returns the actionState to be carried out


  initSystem();

  while(ros::ok()){

      Action action = takeAction();

      switch (action.actionState) {

        // switch through states (action.actionState)
        // if state found, run appropriate function and give it 
        // the object (with it's proerties) as defined above in the takeAction() function. 


          case Tracking:

             makeTrackingAction(action);
             break;

          case Tracking_and_Conversation:
              makeTrackingAndConversationAction(action);

             break;
           case Take_a_photo:
              takeAPhotoAction(action);

             break;

         case RememberMe:

            makeRememberMeAction(action);
            break;

         case EmotionDetection:

            makeEmotionDetectionMeAction(action);
            break;

        default:
            makeTrackingAction(action);
            break;

      }

      ros::spinOnce();
  }






}
