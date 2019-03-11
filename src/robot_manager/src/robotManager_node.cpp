#include "/home/gal/toibot_ws/src/ToiBot1/src/robot_manager/include/robot_managerRos.h"


using namespace std;


int main(int argc, char **argv) {
    ros::init(argc, argv, "robot_manager_node");
    robotManagerRos robotManager;
    ros::spin();
    return 0;
}

