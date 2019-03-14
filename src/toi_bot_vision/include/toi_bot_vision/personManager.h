#include <iostream>

#include <opencv2/opencv.hpp>


#include <dlib/opencv.h>
#include <opencv2/highgui/highgui.hpp>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing/render_face_detections.h>
#include <dlib/image_processing.h>
#include <dlib/gui_widgets.h>

#include "/home/intel/toibot_ws/src/ToiBot1/src/toi_bot_vision/include/toi_bot_vision/FaceTracker.h"

#include "/home/intel/toibot_ws/src/ToiBot1/src/toi_bot_vision/include/toi_bot_vision/emotionDetection.h"




using namespace cv;
using namespace std;
using namespace dlib;




class PersonManager {

public:

    PersonManager();

    virtual ~PersonManager() {

    }

public:

    void getCallback(visionState &state);
    VisionOutputForManager track(visionState &state, const Mat &frame);
    VisionOutputForManager recognize(visionState &state,const Mat &frame);
    void rememberMe(visionState &state, string name ,const Mat &frame);
    VisionOutputForManager detectEmotion(visionState &state, const Mat& frame);






private:

    FaceTracker faceTracker_;
    EmotionDetection emotionDetector_;

};

