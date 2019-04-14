

#include "/home/intel/toibot_ws/src/ToiBot1/src/toi_bot_vision/include/toi_bot_vision/personManager.h"

PersonManager::PersonManager(){

}

void PersonManager::getCallback(visionState &state){

    ifstream commandFile;
    commandFile.open("/home/intel/toibot_ws/src/ToiBot1/src/toi_bot_vision/command.txt");
    std::string   line;

    while(std::getline(commandFile, line)){
        std::stringstream   linestream(line);

        int numState = atoi(line.c_str());
        state = static_cast<visionState>(numState);

    }
    commandFile.close();
    //cout<<" state is "<<state<<endl;


}


VisionOutputForManager PersonManager::track(visionState &state,const Mat& frame){

    VisionOutputForManager visionOutput = faceTracker_.trackeOverFaces(state,frame);

    return visionOutput;



}

void PersonManager::takePhoto(visionState &state,const Mat& frame){

    string path = "/home/intel/toibot_ws/src/ToiBot1/src/toi_bot_vision/party_Imgs";

    //VisionOutputForManager visionOutput = faceTracker_.trackeOverFaces(state,frame);

    if( /*visionOutput.detectFace ==*/ true){

        std::vector<String> images; 
        glob(path, images);

        int index = images.size() + 1;

        imwrite(path + "/"+to_string(index)+".jpg",frame);
    }

    




}

VisionOutputForManager PersonManager::recognize(visionState &state,const Mat &frame){

    VisionOutputForManager visionOutput = faceTracker_.recognizeFace(state,frame);
    return visionOutput;
}

void PersonManager::rememberMe(visionState &state, string name ,const Mat &frame){

        faceTracker_.rememberMe(state, name, frame);

}

void PersonManager::removeFacesDatabase(){
    faceTracker_.removeFacesDatabase();
}

VisionOutputForManager PersonManager::detectEmotion(visionState& state,const Mat& frame){

    Mat cropFace =  faceTracker_.getCropFace(frame);

        if(cropFace.rows > 0 ){

             VisionOutputForManager visionOutputEotion;
             string emotion  = emotionDetector_.detectEmotion(cropFace);
             visionOutputEotion.emotion = emotion;
             //state = visionOutputEotion.state;
            return visionOutputEotion;
        }
        else {
           VisionOutputForManager defaultVisionOutput;
           return defaultVisionOutput;
        }


}

string PersonManager::objectsDetection(visionState& state,const Mat& frame){

   return  faceTracker_.objectsDetection(frame);

}





