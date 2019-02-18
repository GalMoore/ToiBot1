

#include "ros/ros.h"
#include "/home/gal/toibot_ws/src/ToiBot1/src/toi_bot_vision/include/toi_bot_vision/personManager.h"
#include <ctime>
#include "/home/gal/toibot_ws/devel/include/toi_bot_vision/visionMsg.h"

using namespace dlib;
using namespace cv;
using namespace std;


class visionRos{

public:

    visionRos();

    ~visionRos() {

    }

private:

    

    

 private:

    ros::NodeHandle node_;


    ros::Publisher visionPublisher_;

    PersonManager personManager_;


    

};
