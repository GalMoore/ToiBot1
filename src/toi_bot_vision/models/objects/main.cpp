//g++ example.cpp -o app `pkg-config --cflags --libs opencv`
/* {"background",
                            "aeroplane", "bicycle", "bird", "boat",
                            "bottle", "bus", "car", "cat", "chair",
                            "cow", "diningtable", "dog", "horse",
                            "motorbike", "person", "pottedplant",
"sheep", "sofa", "train", "tvmonitor"};*/

// the important
//-- chair(9) --- diningtable(11) --- person(15) --- pottedplant(16) --- sofa(18) ---tvmonitor(20)


#include <opencv2/dnn.hpp>
#include <opencv2/dnn/shape_utils.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
using namespace cv;
using namespace cv::dnn;

#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;

#define SIZE 300

const size_t width = SIZE;
const size_t height = SIZE;

static Mat getMean(const size_t& imageHeight, const size_t& imageWidth)
{
    Mat mean;

    const int meanValues[3] = {104, 117, 123};
    vector<Mat> meanChannels;
    for(int i = 0; i < 3; i++)
    {
        Mat channel((int)imageHeight, (int)imageWidth, CV_32F, Scalar(meanValues[i]));
        meanChannels.push_back(channel);
    }
    cv::merge(meanChannels, mean);
    return mean;
}

static Mat preprocess(const Mat& frame)
{
    Mat preprocessed;
    frame.convertTo(preprocessed, CV_32F);
    resize(preprocessed, preprocessed, Size(width, height)); //SSD accepts 300x300 RGB-images

    Mat mean = getMean(width, height);
    cv::subtract(preprocessed, mean, preprocessed);

    return preprocessed;
}

const char* about = "This sample uses Single-Shot Detector "
                    "(https://arxiv.org/abs/1512.02325)"
                    "to detect objects on image\n"; // TODO: link

const char* params
    = "{ help           | false | print usage         }"
      "{ proto          |       | model configuration }"
      "{ model          |       | model weights       }"
      "{ image          |       | image for detection }"
      "{ min_confidence | 0.5   | min confidence      }";

int main(int argc, char** argv)
{
    int numOfPerson =0;


    String modelConfiguration = "/home/yakir/Downloads/MobileNetSSD_deploy.prototxt.txt"; //parser.get<string>("proto");
    String modelBinary =  "/home/yakir/Downloads/MobileNetSSD_deploy.caffemodel";     //parser.get<string>("model");




    //! [Create the importer of Caffe model]
    Ptr<dnn::Importer> importer;
    importer = dnn::createCaffeImporter(modelConfiguration, modelBinary);


    //! [Initialize network]
    dnn::Net net;
    importer->populateNet(net);
    importer.release();          //We don't need importer anymore

    //! [Initialize network]
    VideoCapture cap("/home/yakir/SightBit/sea2.avi");
    Mat frame;
    Mat outputImg;
    // frame = imread("/home/yakir/SightBit/data/sea9.jpg",1);
    /*double beta = 10;
    double alpha = 2;
    for( int y = 0; y < frame.rows; y++ ) {
        for( int x = 0; x < frame.cols; x++ ) {
            for( int c = 0; c < frame.channels(); c++ ) {
                frame.at<Vec3b>(y,x)[c] =
                  saturate_cast<uchar>( alpha*frame.at<Vec3b>(y,x)[c] + beta );
            }
        }
    }*/
    //resize(frame,frame,Size(frame.cols/2,frame.rows/2));

    int frameount =0;
    VideoWriter out;
    out.open("/home/yakir/SightBit/seaOutput.avi", CV_FOURCC('M', 'J', 'P', 'G'), 15, Size(640,480), true);

    while(1)
    {
        cap >> frame;

        resize(frame,frame,Size(640,480));

        if( frameount > 1600 && frameount < 2000){


            if (frame.channels() == 4)
                cvtColor(frame, frame, COLOR_BGRA2BGR);
            //! [Prepare blob]
            Mat preprocessedFrame = frame;

            Mat inputBlob = blobFromImage(preprocessedFrame, 0.007843, Size(SIZE, SIZE), 127.5); //Convert Mat to batch of images
            //! [Prepare blob]

            //! [Set input blob]
            net.setInput(inputBlob, "data");                //set the network input
            //! [Set input blob]


            cv::TickMeter tm;
            tm.start();
            //! [Make forward pass]
            Mat detection = net.forward("detection_out");                                  //compute output
            //! [Make forward pass]

             tm.stop();

             std::cout << "Inference time, ms: " << tm.getTimeMilli()  << std::endl;


            Mat detectionMat(detection.size[2], detection.size[3], CV_32F, detection.ptr<float>());

           // cout<<"detectionMat size"<<detectionMat.size()<<endl;


            outputImg = frame.clone();

            for(int i = 0; i < detectionMat.rows; i++){
                float confidence =  detectionMat.at<float>(i, 2);


                cout<<"conffff ---"<<confidence<<endl;
                if(confidence > 0.2){



                    size_t objectClass = (size_t)(detectionMat.at<float>(i, 1));

                    float xLeftBottom = detectionMat.at<float>(i, 3) * frame.cols;
                    float yLeftBottom = detectionMat.at<float>(i, 4) * frame.rows;
                    float xRightTop = detectionMat.at<float>(i, 5) * frame.cols;
                    float yRightTop = detectionMat.at<float>(i, 6) * frame.rows;



                    Rect object((int)xLeftBottom, (int)yLeftBottom,
                                (int)(xRightTop - xLeftBottom),
                                (int)(yRightTop - yLeftBottom));

                    if( objectClass ==15){

                        putText(outputImg,"person",Point(object.x, object.y-10),0.5, 0.5,Scalar(0, 255, 0),2);
                        rectangle(outputImg, object, Scalar(0, 255, 0),2);
                        numOfPerson++;
                        cout<<"person   "<<object<<"----"<<confidence<<endl;

                    }
                    /*if( objectClass == 4){

                        putText(outputImg,"boat",Point(object.x, object.y-10),2, 0.5,Scalar(255, 255, 0),2);
                        rectangle(outputImg, object, Scalar(0, 0, 255),2);

                    }*/
                }
            }


            cout<<" numOfPerson "<<numOfPerson<<endl;




             numOfPerson =0;


             out << outputImg;


        }
          cout<<" frameount "<<frameount<<endl;
         frameount++;
         imshow("detections", frame);
         waitKey(1);





    }
    //out.release();


    return 0;
} // main
