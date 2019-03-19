#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

using namespace cv;
using namespace std;


int width = 640;
int height = 480;
int secondBetweenImgs = 5;
string path = "/home/intel/toibot_ws/src/ToiBot1/src/toi_bot_vision/party_Imgs/";
string imgType = "jpg";

std::vector<string> explode(const string& s, const char& c)  {
    string buff{ "" };
    std::vector<string> v;

    for (auto n : s)
    {
        if (n != c) buff += n; else
            if (n == c && buff != "") { v.push_back(buff); buff = ""; }
    }
    if (buff != "") v.push_back(buff);

    return v;
}


void readFromFileData(){

   string line;
  ifstream myfile ("/home/intel/toibot_ws/src/ToiBot1/src/purim_imgs/param.txt");
  int countLine = 0;
  if (myfile.is_open())  {
    while ( getline (myfile,line) )    {
        std::vector<string> lineSplit =explode(line,':');
        if( countLine == 0){
            path = (lineSplit[1]);
        } else if( countLine == 1){
            imgType = (lineSplit[1]);
        } else if( countLine == 2){
            secondBetweenImgs = atoi(lineSplit[1].c_str());

        } else if( countLine == 3){
             width   = atoi(lineSplit[1].c_str());

        } else if( countLine == 4){
             height   = atoi(lineSplit[1].c_str());
            myfile.close();
            return;
        }
        countLine ++;


    }

  }


}

int main(){





    while ( true){

        ///file callback
         readFromFileData();

        cv::String folder =path+"*."+imgType;
        cout<<folder<<endl;
        std::vector<cv::String> Pictures;
        cv::glob(folder, Pictures);


        for(int i = 0; i < Pictures.size(); i ++ ){

            Mat img = imread(Pictures[i],1);

            cout<<" width "<<width<<" height "<<height<<endl;
            Size size(width,height);

            cv::resize(img,img,size);//resize image

            imshow("purim",img);
            waitKey(secondBetweenImgs * 1000);

        }
    }



    return 0;
}
