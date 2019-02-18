#include "ros/ros.h"
#include "std_msgs/String.h"

using namespace std;

// SubscribeAndPublish object subscribes to topic, check if any new msg is 
// found on topic and in callback republishes the new found 
// contents of topic to new topic that holds only the changes on this topic
class SubscribeAndPublish
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
      // if some new input has arrived publish to topic (this will be said by text to speech)
      output = input;
      pub_.publish(output);
      currentQuery = input.data;
  }

private:
  ros::NodeHandle n_; 
  ros::Publisher pub_;
  ros::Subscriber sub_;

};//End of class SubscribeAndPublish

int main(int argc, char **argv)
{
  //Initiate ROS
  ros::init(argc, argv, "subscribe_and_publish");

  //Create an object of class SubscribeAndPublish that will take care of everything
  SubscribeAndPublish SAPObject;

  ros::spin();

  return 0;
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






































































