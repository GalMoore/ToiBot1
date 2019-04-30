
#include "/home/intel/toibot_ws/src/ToiBot1/src/robot_manager/include/robot_managerRos.h"

#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>


using namespace std;

void robotManagerRos::initSystem(){

    //init once
    if(init_ == false){

        visonSubInut_ =    node_.subscribe("vision_publisher_output", 1,  &robotManagerRos::visionCallback, this);

        voiceSubInput_ =    node_.subscribe("/stt_topic", 1, &robotManagerRos::voiceCallback, this);

        visionFeatureInput_ = node_.subscribe("vision_publisher_features_output", 1, &robotManagerRos::visionFeaturesCallback, this);

        ///emotion, recognition .... 
        visionFeaturePublisher_ = node_.advertise<toi_bot_vision::visionMsgFeatures>("vision_publisher_features",1000, true);

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

void robotManagerRos::visionCallback(const toi_bot_vision::visionMsgOutput& msg){


    visionInput_.detectFace = msg.detectFace;
    visionInput_.deltaX = msg.deltaX;
    visionInput_.deltaY = msg.deltaY;
    visionInput_.canRecognize = msg.canRecognize;
    visionInput_.name = msg.name;
    visionInput_.emotion = msg.emotion;
    visionInput_.faceArea = msg.faceArea;


}
void robotManagerRos::visionFeaturesCallback(const toi_bot_vision::visionMsgFeatureOutput& msg){

    string answer = msg.featureAnswer;
    cout<<" the answer is "<<answer<<endl;
    /// emotion answer
    if( (answer.find("sad") != string::npos) || 
          (answer.find("happy") != string::npos) ||
           (answer.find("neutral") != string::npos) ||
           (answer.find("surprised") != string::npos)  ){
          
        toi_bot_speakers::speakersCommand speakersMsg;
        speakersMsg.response =  " you are look very "+ answer;
        speakersPublisher_.publish(speakersMsg);
        canTalkByDialogFlow = true;
    }
    ///remember me 
    else if ( (answer.find("it's done") != string::npos) ){
        string name = answer;  
        toi_bot_speakers::speakersCommand speakersMsg;
        speakersMsg.response = answer;
        speakersPublisher_.publish(speakersMsg);
        canTalkByDialogFlow = true;
    }
     // face recognition
      else if ( (answer.find("your name is") != string::npos) ||
          (answer.find("know you yet") != string::npos) ){
        string name = answer;  
        toi_bot_speakers::speakersCommand speakersMsg;
        speakersMsg.response = answer;
        speakersPublisher_.publish(speakersMsg);
        canTalkByDialogFlow = true;
    } 
    // objects recognition
      else if ( (answer.find("i see") != string::npos)  ){
        toi_bot_speakers::speakersCommand speakersMsg;
        speakersMsg.response = answer;
        speakersPublisher_.publish(speakersMsg);
        canTalkByDialogFlow = true;
    } 
    // remove faces database 
      else if ( (answer.find("faces database") != string::npos)  ){
        toi_bot_speakers::speakersCommand speakersMsg;
        speakersMsg.response = answer;
        speakersPublisher_.publish(speakersMsg);
        canTalkByDialogFlow = true;
    } 
    // take a photo 
    else if ( (answer.find("ok, don't forget to smile") != string::npos)  ){
        toi_bot_speakers::speakersCommand speakersMsg;
        speakersMsg.response = answer;
        speakersPublisher_.publish(speakersMsg);
        canTalkByDialogFlow = true;
    } 
    

    
}
void robotManagerRos::voiceCallback(const toi_bot_stt::speechTT &msg){

  voiceInput_.query = msg.query;
  voiceInput_.response = msg.response;
  voiceInput_.intent = msg.intent;

  if( voiceInput_.query !=""){
     //cout<<"query"<<voiceInput_.query<<" response "<<voiceInput_.response<<endl;

  }

}



void robotManagerRos::takeActionOfVisionFeaturesSim(){

    ///emotion
    if (lastCommandWasEmotion == false && (voiceInput_.query.find("my mood") != string::npos) 
      ){
         makeEmotionDetectionMeAction();
         lastCommandWasEmotion = true; 
         canTalkByDialogFlow = false;
    } 
    if( !(voiceInput_.query.find("my mood") != string::npos) ){
        lastCommandWasEmotion = false;
    } 

    ////remember me 
    if (lastCommandWasRememberMe == false && (voiceInput_.query.find("remember me") != string::npos) 
      ){
         
         
         makeRememberMeAction(voiceInput_.query);
         lastCommandWasRememberMe = true; 
         canTalkByDialogFlow = false;
    } 
    if( !(voiceInput_.query.find("remember me") != string::npos) ){
        lastCommandWasRememberMe = false;
    } 

    /// face recognition
    if (lastCommandWasRecognition == false && (voiceInput_.query.find("recognize me") != string::npos) 
      ){    
         
         makeRecognitionAction();
         lastCommandWasRecognition = true; 
         canTalkByDialogFlow = false;
    } 
    if( !(voiceInput_.query.find("recognize me") != string::npos) ){
        lastCommandWasRecognition = false;
    } 

    /// objects recognition
    if (lastCommandWasObjectsRecognition == false && (voiceInput_.query.find("what do you see") != string::npos) 
      ){    
         
         makeObjectsRecognitionAction();
         lastCommandWasObjectsRecognition = true; 
         canTalkByDialogFlow = false;
    } 
    if( !(voiceInput_.query.find("what do you see") != string::npos) ){
        lastCommandWasObjectsRecognition = false;
    } 

    /// cleaning faces database
    if (lastCommandWasCleaningFacesDatabase == false && (voiceInput_.query.find("remove faces database") != string::npos) 
      ){    
         
         makecCleaningFacesDatabaseAction();
         lastCommandWasCleaningFacesDatabase = true; 
         canTalkByDialogFlow = false;
    } 
    if( !(voiceInput_.query.find("remove faces database") != string::npos) ){
        lastCommandWasCleaningFacesDatabase = false;
    } 

    if ( lastCommandWasTakeAPhoto == false && (voiceInput_.query.find("take a photo") != string::npos) || 
          (voiceInput_.query.find("take a picture") != string::npos)  ){
          
          makeTakeAPhotoAction();
          lastCommandWasTakeAPhoto = true; 
          canTalkByDialogFlow = false;          
    }

    if( !(voiceInput_.query.find("take a photo") != string::npos || 
         voiceInput_.query.find("take a picture") != string::npos) ){
        lastCommandWasTakeAPhoto = false;
    }

}

Action robotManagerRos::takeAction(){


    takeActionOfVisionFeaturesSim();   

   
    /// tracking and conversation

    Action action;
    action.actionState = Tracking_and_Conversation;

    action.visionMsgOutput.visionStateOutput = tracking;

    /// speakers    
    action.speakersMsgOutput.response = voiceInput_.response;
    action.speakersMsgOutput.query = voiceInput_.query;


    return action;


   


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

    if (canTalkByDialogFlow == true){
        //If the message received from Dialogflow is not empty
      if( action.speakersMsgOutput.response != ""){
        // and the query heard from user is new (not same as last query)
        if( action.speakersMsgOutput.query!= lastStringQueryPublished_){
          // publish the response from dialogflow to speakers to be spoken! 
          //speakersPublisher_.publish(speakersMsg);
          lastStringQueryPublished_= action.speakersMsgOutput.query;

          motorsMsg.setnence = action.speakersMsgOutput.response;

        }
      }
    }     

     motorsPublisher_.publish(motorsMsg);

     ros::spinOnce();
     loop_rate_.sleep();


}

void robotManagerRos::makeRememberMeAction(string query){

    ///remember 
    toi_bot_vision::visionMsgFeatures m;
    m.feature =query;
    visionFeaturePublisher_.publish(m);

    
    ros::spinOnce();
    loop_rate_.sleep();

}

void robotManagerRos::makeEmotionDetectionMeAction(){

    ///emotion
    toi_bot_vision::visionMsgFeatures m;
    m.feature ="emotion";
    visionFeaturePublisher_.publish(m);

    
    ros::spinOnce();
    loop_rate_.sleep();

}

void robotManagerRos::makeRecognitionAction(){

    toi_bot_vision::visionMsgFeatures m;
    m.feature ="recognition";
    visionFeaturePublisher_.publish(m);

    
    ros::spinOnce();
    loop_rate_.sleep();

}

void robotManagerRos::makeObjectsRecognitionAction(){

    toi_bot_vision::visionMsgFeatures m;
    m.feature ="objects";
    visionFeaturePublisher_.publish(m);

    
    ros::spinOnce();
    loop_rate_.sleep();

}

void robotManagerRos::makecCleaningFacesDatabaseAction(){

    toi_bot_vision::visionMsgFeatures m;
    m.feature ="remove database";
    visionFeaturePublisher_.publish(m);

    
    ros::spinOnce();
    loop_rate_.sleep();

}

void robotManagerRos::makeTakeAPhotoAction(){


    toi_bot_vision::visionMsgFeatures m;
    m.feature = "take photo";
    visionFeaturePublisher_.publish(m);

    
    ros::spinOnce();
    loop_rate_.sleep();


}


robotManagerRos::robotManagerRos(){

  //  loop through the while. Each time query takeAction()
  // which returns the actionState to be carried out


  initSystem();

  while(ros::ok()){

      Action action = takeAction();

      switch (action.actionState) {
       
        case Tracking_and_Conversation:
            makeTrackingAndConversationAction(action);

            break;
        
        default:
          makeTrackingAndConversationAction(action);
          break;

      }

      ros::spinOnce();
  }






}
