
#include "/home/gal/toibot_ws/src/ToiBot1/src/robot_manager/include/robot_managerRos.h"


using namespace std;


/*class SubscribeAndPublish
{
public:
  string currentQuery;

  SubscribeAndPublish()
  {
    //Topic you want to publish
    pub_ = n_.advertise<std_msgs::String>("/published_topic_from_manager", 1);
    //Topic you want to subscribe
    sub_ = n_.subscribe("/response_text_topic", 1, &SubscribeAndPublish::callback, this);
  }

  void callback(std_msgs::String input)
  { 
    // Subscribes to last string heard from 
    // user and publishes that string or a command to topic
    std_msgs::String output;
    // cout<<"input.data = " <<input.data<<endl;
    // cout<<"currentQuery = " << currentQuery<<endl;
    int resultCompare = currentQuery.compare(input.data);
    // cout<<"resultCompare = " <<resultCompare<<endl;
    if(currentQuery.compare(input.data)==0)
    //     // cout<<"no change in query"<<endl;
      // cout<<"they are the same!"<<endl;
        ;
    else
      output = input;
      pub_.publish(output);
      currentQuery = input.data;
  }

private:
  ros::NodeHandle n_; 
  ros::Publisher pub_;
  ros::Subscriber sub_;

};//End of class SubscribeAndPublish
*/


void robotManagerRos::visionCallback(const toi_bot_vision::visionMsgOutput& msg){


    visionInput_.detectFace = msg.detectFace;
    visionInput_.deltaX = msg.deltaX;
    visionInput_.deltaY = msg.deltaY;
    visionInput_.canRecognize = msg.canRecognize;
    visionInput_.name = msg.name;
    visionInput_.emotion = msg.emotion;

    /*cout<<visionInput_.detectFace<<endl;
    cout<<visionInput_.deltaX<<endl;
    cout<<visionInput_.deltaY<<endl;
    cout<<visionInput_.canRecognize<<endl;
    cout<<visionInput_.name<<endl;
    cout<<visionInput_.emotion<<endl;
    cout<<"---------------------"<<endl;*/




}

void robotManagerRos::voiceCallback(std_msgs::String input){


  string currentQuery;

  std_msgs::String output;

  int resultCompare = currentQuery.compare(input.data);

  if(currentQuery.compare(input.data)==0){

      // cout<<"no change in query"<<endl;
     // cout<<"they are the same!"<<endl;
     voiceInput_.inputText ="";

  }

  else{

    voiceInput_.inputText = input.data;
  }
}

void robotManagerRos::initSystem(){

    //init once
    if(init_ == false){

        visonSubInut_ =    node_.subscribe("vision_publisher_output", 1,  &robotManagerRos::visionCallback, this);
        voiceSubInput_ =    node_.subscribe("query_text_topic", 1, &robotManagerRos::voiceCallback, this);

        visionPublisher_ = node_.advertise<toi_bot_vision::visionMsgCommand>(
                    "vision_publisher_command", 1, true);

        ///motors
        motorsPublisher_ = node_.advertise<motors::motorsCommand>(
                    "motors_publisher_command", 1, true);

        ///speakers



        init_ = true;
    }
}

Action robotManagerRos::takeAction(){

    cout<<voiceInput_.inputText <<endl;

   /* if( voiceInput_.inputText == "remember me" ){

        Action action;
        action.actionState = RememberMe;

        VisionMsgOutput visionMsgOutput;
        visionMsgOutput.visionStateOutput = memorization;
        visionMsgOutput.nameToRemember = "yakir ";
        action.visionMsgOutput = visionMsgOutput;

        return action;


    } else {

        Action action;
        action.actionState = Tracking;

        VisionMsgOutput visionMsgOutput;
        visionMsgOutput.visionStateOutput = tracking;
        action.visionMsgOutput = visionMsgOutput;

        return action;

    }*/


    Action action;
    action.actionState = Tracking;

    VisionMsgOutput visionMsgOutput;
    visionMsgOutput.visionStateOutput = tracking;
    action.visionMsgOutput = visionMsgOutput;

    return action;






}

void robotManagerRos::makeTrackingAction(const Action& Action){

    ///vision part
    toi_bot_vision::visionMsgCommand visionMsg;
    visionMsg.visionStateCommand = visionState::tracking;
    visionMsg.personName = "unknown";
    visionPublisher_.publish(visionMsg);

    ///motors part
    motors::motorsCommand motorsMsg;

    if(visionInput_.detectFace == true) {

       motorsMsg.deltaX =  visionInput_.deltaX;
       motorsMsg.deltaY =  visionInput_.deltaY;
       motorsMsg.sentence =" yakir ";
       cout<<"  motorsMsg.deltaX "<<(int)motorsMsg.deltaX<<endl;

       motorsPublisher_.publish(motorsMsg);

       ros::spinOnce();
       loop_rate_.sleep();

    } else {

        motorsMsg.deltaX =  0;
        motorsMsg.deltaY =  0;
        motorsMsg.sentence ="";

        motorsPublisher_.publish(motorsMsg);

        ros::spinOnce();
        loop_rate_.sleep();
    }



}

void robotManagerRos::makeRememberMeAction(const Action& Action){

     ///vision part
    toi_bot_vision::visionMsgCommand m;
    m.visionStateCommand = visionState::memorization;
    m.personName = Action.visionMsgOutput.nameToRemember;
    visionPublisher_.publish(m);

    ros::spinOnce();
    loop_rate_.sleep();

}

void robotManagerRos::makeEmotionDetectionMeAction(const Action& Action){

    ///vision part
    toi_bot_vision::visionMsgCommand m;
    m.visionStateCommand = visionState::emotionRecognition;
    m.personName = "";
    visionPublisher_.publish(m);

    ros::spinOnce();
    loop_rate_.sleep();

}



robotManagerRos::robotManagerRos(){


  initSystem();

  while(ros::ok()){

      Action action = takeAction();

      switch (action.actionState) {


          case Tracking:

             makeTrackingAction(action);
             break;

          case Tracking_and_Conversation:

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








// //  THIS WORKS! 
// // /**
// //  * Check incoming topics and decide how to react 
// //  */

// string currentQuery;

// void publish_to_motors()
// {
//   ros::NodeHandle r;
//   ros::Publisher manager_pub = r.advertise<std_msgs::String>("manager_send_command", 1000);
//   std_msgs::String msg;
//   msg.data = "yo here is a command";
//   manager_pub.publish(msg);
//   ros::spinOnce();
//   cout<<"checking"<<endl;

// }

// void queryCallback(const std_msgs::String::ConstPtr& msg)
// {

//   if(currentQuery.compare(msg->data.c_str())==0)
//     // cout<<"no change in query"<<endl;
//     ;
//   else
//     // prints new query as arrives 
//     cout<<msg->data.c_str()<<endl;
//     publish_to_motors();
//     currentQuery = msg->data.c_str();
// }



// int main(int argc, char **argv)
// {
//   ros::init(argc, argv, "robot_manager_node");

//   ros::NodeHandle n;

//   // subscribe to some topic
//   ros::Subscriber sub = n.subscribe("query_text_topic", 1000, queryCallback);
//   ros::spin();
//   return 0;
// }






































































