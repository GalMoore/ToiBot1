
#include "ros/ros.h"
#include "/home/intel/toibot_ws/src/ToiBot1/src/toi_bot_vision/include/toi_bot_vision/personManager.h"
#include <ctime>



#include "/home/intel/toibot_ws/devel/include/toi_bot_vision/visionMsgOutput.h"
#include "/home/intel/toibot_ws/devel/include/toi_bot_vision/visionMsgCommand.h"


using namespace dlib;
using namespace cv;
using namespace std;




class visionRos{

public:

    visionRos();

    ~visionRos() {

    }

    void initSystem();


    void visionCallbackCommand(const toi_bot_vision::visionMsgCommand& msg);

    void convertVisionStructToMsg(toi_bot_vision::visionMsgOutput& m,
                                  VisionOutputForManager visionOutput);





    

 private:

    ros::NodeHandle node_;

    bool init_ = false;


    ros::Publisher visionPublisher_;
    ros::Subscriber visonSubCommand_;





    PersonManager personManager_;

    visionState state_ = init ;
    string name_ = "";

    cv::VideoCapture cap = VideoCapture(0);


    

};
