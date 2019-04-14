
#include <iostream>
#include <string>

using namespace  std;

enum visionState { init = 1, tracking = 2, recognition = 3 , memorization = 4, emotionRecognition = 5 , takePhoto = 6 };




struct VisionOutputForManager{

 bool detectFace = false;
 int32_t deltaX = 100000;
 int32_t deltaY = 100000;
 bool canRecognize = false;
 string name = "";
 string emotion = "";
 int32_t faceArea = 0;


};


