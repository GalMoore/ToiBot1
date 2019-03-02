
#include <iostream>
#include <string>

using namespace  std;

enum visionState { init = 1, tracking = 2, recognition = 3 , memorization = 4, emotionRecognition = 5  };




struct VisionOutputForManager{

 bool detectFace = false;
 int deltaX = 0;
 int deltaY = 0;
 bool canRecognize = false;
 string name = "";
 string emotion = "";


};



