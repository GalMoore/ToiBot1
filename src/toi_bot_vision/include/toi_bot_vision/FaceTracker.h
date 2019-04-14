#include <iostream>

#include <opencv2/opencv.hpp>


#include <dlib/opencv.h>
#include <opencv2/highgui/highgui.hpp>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing/render_face_detections.h>
#include <dlib/image_processing.h>
#include <dlib/gui_widgets.h>
#include <dlib/dnn.h>
#include <dlib/gui_widgets.h>
#include <dlib/clustering.h>
#include <dlib/string.h>
#include <dlib/image_io.h>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/svm.h>
#include <fstream>

#include <chrono>
#include <thread>



// #include <opencv2/dnn.hpp>
// #include <opencv2/dnn/shape_utils.hpp>
// #include <opencv2/imgproc.hpp>
// #include <opencv2/highgui.hpp>

#include "/home/intel/toibot_ws/src/ToiBot1/src/toi_bot_vision/include/toi_bot_vision/visionParams.h"



using namespace cv;
//using namespace cv::dnn;

using namespace std;
using namespace dlib;






template <template <int,template<typename>class,int,typename> class block, int N, template<typename>class BN, typename SUBNET>
using residual = add_prev1<block<N,BN,1,tag1<SUBNET>>>;

template <template <int,template<typename>class,int,typename> class block, int N, template<typename>class BN, typename SUBNET>
using residual_down = add_prev2<avg_pool<2,2,2,2,skip1<tag2<block<N,BN,2,tag1<SUBNET>>>>>>;

template <int N, template <typename> class BN, int stride, typename SUBNET>
using block  = BN<con<N,3,3,1,1,relu<BN<con<N,3,3,stride,stride,SUBNET>>>>>;

template <int N, typename SUBNET> using ares      = relu<residual<block,N,affine,SUBNET>>;
template <int N, typename SUBNET> using ares_down = relu<residual_down<block,N,affine,SUBNET>>;

template <typename SUBNET> using alevel0 = ares_down<256,SUBNET>;
template <typename SUBNET> using alevel1 = ares<256,ares<256,ares_down<256,SUBNET>>>;
template <typename SUBNET> using alevel2 = ares<128,ares<128,ares_down<128,SUBNET>>>;
template <typename SUBNET> using alevel3 = ares<64,ares<64,ares<64,ares_down<64,SUBNET>>>>;
template <typename SUBNET> using alevel4 = ares<32,ares<32,ares<32,SUBNET>>>;

using anet_type = loss_metric<fc_no_bias<128,avg_pool_everything<
                            alevel0<
                            alevel1<
                            alevel2<
                            alevel3<
                            alevel4<
                            max_pool<3,3,2,2,relu<affine<con<32,7,7,2,2,
                            input_rgb_image_sized<150>
                            >>>>>>>>>>>>;

typedef matrix<double, 68, 1> sample_type;
typedef radial_basis_kernel<sample_type> kernel_type;
typedef probabilistic_decision_function<kernel_type> probabilistic_funct_type;
typedef normalized_function<probabilistic_funct_type> pfunct_type;


class FaceTracker {

public:

    FaceTracker();

    virtual ~FaceTracker() {

    }

public:

    VisionOutputForManager trackeOverFaces(visionState &state, const Mat& frame );

    VisionOutputForManager recognizeFace(visionState &state, const Mat& frame);

    void rememberMe(visionState &state, string name ,const Mat &frame);

    void removeFacesDatabase();



    double checkMatch(std::vector<matrix<float,0,1>> faceOrig_descriptors ,
                                    string faceFolderPath);


    std::vector<string> getAllNamesOfFoldersInDir(string path) const;

    bool checkIfFolderIsEmpty(string path) const;

    void createFolderWithName(string folderName, string path) const;

    Mat getCropFace(const Mat& frame);

    string objectsDetection(const Mat& frame);


    string detectShirtColor(cv::Rect faceRect, const Mat& frame);
    string findBestColor(const Mat& crop);

    void removeFolder(const char* path);







private:

    image_window win;

    shape_predictor pose_model_;
    frontal_face_detector detector_ = get_frontal_face_detector();

    shape_predictor sp;
    anet_type net;

    bool canRecognizeAgain_ = true;

    pfunct_type learned_pfunct;

    //dnn::Net net;







};

