
#include "ros/ros.h"
#include "/home/intel/toibot_ws/src/ToiBot1/src/toi_bot_vision/include/toi_bot_vision/personManager.h"
#include "/home/intel/toibot_ws/src/ToiBot1/src/toi_bot_vision/include/toi_bot_vision/FoldersManagment.h"

#include <ctime>



#include "/home/intel/toibot_ws/devel/include/toi_bot_vision/visionMsgOutput.h"
#include "/home/intel/toibot_ws/devel/include/toi_bot_vision/visionMsgCommand.h"
#include "/home/intel/toibot_ws/devel/include/toi_bot_vision/visionMsgFeatures.h"
#include "/home/intel/toibot_ws/devel/include/toi_bot_vision/visionMsgFeatureOutput.h"





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

    void visionCallbackFeature(const toi_bot_vision::visionMsgFeatures& msg);


    void convertVisionStructToMsg(toi_bot_vision::visionMsgOutput& m,
                                  VisionOutputForManager visionOutput);





    

 private:

    ros::NodeHandle node_;

    cv::Mat frame;


    bool init_ = false;


    ros::Publisher visionPublisher_;
    ros::Subscriber visonSubCommand_;

    ros::Subscriber visonSubFeature_;
    ros::Publisher visionFeaturePublisherOutput_;

    FoldersManagment foldersManagment_;







    PersonManager personManager_;

    visionState state_ = init ;
    string name_ = "";

    cv::VideoCapture cap = VideoCapture(0);


    

};
