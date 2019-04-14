
#include "/home/intel/toibot_ws/src/ToiBot1/src/toi_bot_vision/include/toi_bot_vision/visionRos.h"


using namespace std;



int main(int argc, char **argv) {

    ros::init(argc, argv, "vision_node");
    visionRos visionManager;
    ros::spin();
    return 0;
}
