#include "/home/intel/toibot_ws/src/ToiBot1/src/toi_bot_vision/include/toi_bot_vision/FaceTracker.h"


FaceTracker::FaceTracker(){

    ///face detection with landsmark
    deserialize("/home/intel/toibot_ws/src/ToiBot1/src/toi_bot_vision/models/shape_predictor_68_face_landmarks.dat") >> pose_model_;

    //face recognition
    deserialize("/home/intel/toibot_ws/src/ToiBot1/src/toi_bot_vision/models/dlib_face_recognition_resnet_model_v1.dat") >> net;


    ///dnn objects detection

    // String modelConfiguration = "/home/intel/toibot_ws/src/ToiBot1/src/toi_bot_vision/models/MobileNetSSD_deploy.prototxt.txt"; //parser.get<string>("proto");
    // String modelBinary =  "/home/intel/toibot_ws/src/ToiBot1/src/toi_bot_vision/models/MobileNetSSD_deploy.caffemodel";   


    // //! [Create the importer of Caffe model]
    // Ptr<dnn::Importer> importer;
    // importer = dnn::createCaffeImporter(modelConfiguration, modelBinary);


    // //! [Initialize network]
    // importer->populateNet(net);
    // importer.release();          //We don't need importer anymore


}


VisionOutputForManager FaceTracker::trackeOverFaces(visionState& state,const Mat& frame){


    std::vector<std::vector<cv::Point> > landmarksFaces;
    std::vector<cv::Rect> facesRects;
    cv_image<bgr_pixel> cimg(frame);

    // Detect faces
    std::vector<dlib::rectangle> faces = detector_(cimg);
    // Find the pose of each face.
    std::vector<full_object_detection> shapes;

    Rect closestRectCenter;
    double  minDistRectCenter = 1000000;
    for (unsigned long i = 0; i < faces.size(); ++i){
        dlib:: rectangle r = faces[i];
        dlib::point tl = r.tl_corner();
        int x = tl.x();
        int y = tl.y();
        cv::Rect cvRect = Rect(x,y,r.width(),r.height());
        double distCenter =  sqrt(pow((cvRect.x - frame.cols), 2) +
                                  pow((cvRect.y - frame.rows), 2));
        if ( distCenter < minDistRectCenter){
            minDistRectCenter = distCenter;
            closestRectCenter = cvRect;
        }

        facesRects.push_back(cvRect);
        int scale = 1;
        shapes.push_back(pose_model_(cimg, faces[i]));
        std::vector<cv::Point>  landmarks;
        for(unsigned int j = 0; j< shapes[i].num_parts();++j)
            {
                landmarks.push_back(Point(shapes[i].part(j).x()*(1/scale),shapes[i].part(j).y()*(1/scale)));
        }
        landmarksFaces.push_back(landmarks);
    }
    /*for(int i = 0; i < landmarksFaces.size(); i++){
        std::vector<cv::Point>  landmarks = landmarksFaces[i];

        for (int j = 0; j < landmarks.size(); j++){
            cv::Point p = landmarks[j];
            circle(tmp, p,1, Scalar(0,0,0), -1, 8, 0);
        }


    }*/

    ///no faces at all
    if(facesRects.size() == 0 ){

        canRecognizeAgain_ = true;
        state = tracking;



        VisionOutputForManager visionOutput;

         visionOutput.detectFace = false;
         visionOutput.deltaX = 100000;
         visionOutput.deltaY = 100000;
         visionOutput.canRecognize = false;
         visionOutput.name = "";
         visionOutput.emotion = "";


         return visionOutput;
    }

    Mat tmp = frame.clone();
    Rect r = closestRectCenter;
    double area = r.area();
    cv::rectangle(tmp,r,cv::Scalar(0,255,0),2,8,0);

                     


    VisionOutputForManager visionOutput;

    state = tracking;


    visionOutput.detectFace = true;

    Point faceCenter = Point( (r.x + r.width /2), (r.y + r.height /2) );
    Point frameCenter = Point((frame.cols/2), (frame.rows/2));

    visionOutput.deltaX = frameCenter.x - faceCenter.x;


    visionOutput.deltaY = frameCenter.y - faceCenter.y;
    visionOutput.canRecognize = false;
    visionOutput.name = "";
    visionOutput.emotion = "";
    visionOutput.faceArea = area;


    circle(tmp, faceCenter,5, Scalar(0,255,0), -1, 8, 0);
    circle(tmp, frameCenter,5, Scalar(255,0,0), -1, 8, 0);

    cv::putText(tmp,to_string(visionOutput.deltaX)+","+to_string(visionOutput.deltaY),
                cv::Point(100,100),1, 3, cv::Scalar(0,255,0),3,8);



    imshow("tracker",tmp);
    waitKey(1);

    return visionOutput;

}

VisionOutputForManager FaceTracker::recognizeFace(visionState &state,const Mat& frame){

        canRecognizeAgain_ = false;

        /// folder is empty

        string path = "/home/intel/toibot_ws/src/ToiBot1/src/toi_bot_vision/faces";
        if( checkIfFolderIsEmpty(path) == true){


            state = tracking;

            VisionOutputForManager visionOutput;

            visionOutput.detectFace = true;
            visionOutput.deltaX = 0;
            visionOutput.deltaY = 0;
            visionOutput.canRecognize = false;
            visionOutput.name = "";
            visionOutput.emotion = "";

            return visionOutput;
        }

        ////calc cuurent face

        cv_image<bgr_pixel> image(frame);
        matrix<rgb_pixel> imgOriginal;
        assign_image(imgOriginal, image);

        std::vector<matrix<rgb_pixel>> facesOriginal;
        for (auto face : detector_(imgOriginal)){

           auto shape = pose_model_(imgOriginal, face);
           matrix<rgb_pixel> face_chip;
           extract_image_chip(imgOriginal, get_face_chip_details(shape,150,0.25), face_chip);
           facesOriginal.push_back(move(face_chip));

        }

        if ( facesOriginal.size() != 1){
           
            state = tracking;

            VisionOutputForManager visionOutput;

            visionOutput.detectFace = true;
            visionOutput.deltaX = 0;
            visionOutput.deltaY = 0;
            visionOutput.canRecognize = false;
            visionOutput.name = "";
            visionOutput.emotion = "";

            return visionOutput; 

        }

        std::vector<matrix<float,0,1>> faceOrig_descriptors;
        faceOrig_descriptors = net(facesOriginal);


        ///run over all the folders
        std::vector<string> names = getAllNamesOfFoldersInDir(path);

        string bestName;
        double minError = 1;
        for( int i =0; i < names.size(); i++){

           string pathName = (path) +"/"+ names[i];
           double error = checkMatch(faceOrig_descriptors,pathName);
            if( error <  minError){

                bestName = names[i];
                minError = error;


            }

        }

    state = tracking;

    VisionOutputForManager visionOutput;

    visionOutput.detectFace = true;
    visionOutput.deltaX = 0;
    visionOutput.deltaY = 0;
    visionOutput.canRecognize = true;
    visionOutput.name = bestName;
    visionOutput.emotion = "";

    return visionOutput;




}

double FaceTracker::checkMatch(std::vector<matrix<float,0,1>> faceOrig_descriptors ,
                                string faceFolderPath){


    ////calc img from folder
    cv::String folder = faceFolderPath+"/*.jpg";
    std::vector<cv::String> picturesInFolder;
    cv::glob(folder, picturesInFolder);
    Mat imgFromFolder = imread(picturesInFolder[0],1);


    cv_image<bgr_pixel> image(imgFromFolder);
    matrix<rgb_pixel> imgFolder;
    assign_image(imgFolder, image);



    std::vector<matrix<rgb_pixel>> faceFolder;
    for (auto face : detector_(imgFolder)){

       auto shape = pose_model_(imgFolder, face);
       matrix<rgb_pixel> face_chip;
       extract_image_chip(imgFolder, get_face_chip_details(shape,150,0.25), face_chip);
       faceFolder.push_back(move(face_chip));

    }
    std::vector<matrix<float,0,1>> faceFolder_descriptors;
    faceFolder_descriptors = net(faceFolder);


    double l = length(faceOrig_descriptors[0]-faceFolder_descriptors[0]) ;


    return l;


}

std::vector<string> FaceTracker::getAllNamesOfFoldersInDir(string path) const {


    std::vector<string> names;
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir (path.c_str())) != NULL) {
      /* print all the files and directories within directory */
      while ((ent = readdir (dir)) != NULL) {
        //printf ("%s\n", ent->d_name);
        string s = ent->d_name;
        if (s.find("..") != std::string::npos
                || s.find(".") != std::string::npos) {
        }
        else{
           names.push_back(s);
        }
      }
      closedir (dir);
    }
    return names;

}
Mat FaceTracker::getCropFace(const Mat& frame){


    std::vector<cv::Rect> facesRects;
    Mat tmp = frame.clone();
    cv_image<bgr_pixel> cimg(frame);

    // Detect faces
    std::vector<dlib::rectangle> faces = detector_(cimg);
    // Find the pose of each face.
    std::vector<full_object_detection> shapes;

    if( faces.size() == 1){
        for (unsigned long i = 0; i < faces.size(); ++i){
            dlib:: rectangle r = faces[i];
            dlib::point tl = r.tl_corner();
            int x = tl.x();
            int y = tl.y();
            cv::Rect cvRect = Rect(x,y,r.width(),r.height());
            //cv::rectangle(tmp,cvRect,cv::Scalar(0,255,0),2,8,0);
             if(cvRect.x > 0 && cvRect.y > 0 &&
                     cvRect.x + cvRect.width < tmp.cols && cvRect.y +cvRect.height < tmp.rows  ){
                 cv::Mat croppedImage = tmp(cvRect);

                 resize(croppedImage,croppedImage,cv::Size(310,310));
                 return croppedImage;
             }

             else {
                 Mat empty(0,0, CV_8U, cv::Scalar(0));
                 return empty;
             }


        }
    } else {
        Mat empty(0,0, CV_8U, cv::Scalar(0));
        return empty;
    }






}

void FaceTracker::rememberMe(visionState &state, string name ,const Mat &frame){

    // detect the face and make crop
    std::vector<cv::Point> landmarks;
    std::vector<cv::Rect> facesRects;
    Mat tmp = frame.clone();
    cv_image<bgr_pixel> cimg(frame);

    // Detect faces
    std::vector<dlib::rectangle> faces = detector_(cimg);
    // Find the pose of each face.
    std::vector<full_object_detection> shapes;

    if( faces.size() == 1  ){

        dlib:: rectangle r = faces[0];
        dlib::point tl = r.tl_corner();
        int x = tl.x();
        int y = tl.y();
        cv::Rect cvRect = Rect(x,y,r.width(),r.height());
        Mat faceCrop = frame(cvRect).clone();


        /// create folder with name
        string path = "/home/intel/toibot_ws/src/ToiBot1/src/toi_bot_vision/faces";

        string pathName = (path) +"/"+name;

        createFolderWithName(name, path);
        waitKey(1000);

        imwrite(pathName+"/"+name+".jpg",frame);

        state = init;

    }
     else {

        cout<<" cant detect face !!  "<<endl;
        state = init;
    }



}

void FaceTracker::createFolderWithName(string folderName, string path) const {

    int status;
    string newPath = path+"/"+ folderName;

    cout<<newPath<<endl;

    char *finalPath = new char[newPath.length() + 1];
    std::strcpy(finalPath,newPath.c_str());

    ///create folder
    status = mkdir(finalPath, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

    delete [] finalPath;

}



void FaceTracker::removeFolder(const char* path){
    
    struct dirent *entry = NULL;
    DIR *dir = NULL;
    dir = opendir(path);
    while(entry = readdir(dir))
    {   
            DIR *sub_dir = NULL;
            FILE *file = NULL;
            char abs_path[300] = {0};
            if(*(entry->d_name) != '.')
            {   
                    sprintf(abs_path, "%s/%s", path, entry->d_name);
                   
                    if(sub_dir = opendir(abs_path))
                    {       
                            closedir(sub_dir);

                            /// remove the img
                             string pathWithFolderNumber(abs_path);
                             cv::String folder = pathWithFolderNumber+"/*.jpg";
                             std::vector<cv::String> Pictures;
                             cv::glob(folder, Pictures);
                             remove(Pictures[0].c_str());

                            remove(abs_path);
                    } 
                    
            }   
    }   
    remove(path);
}
    

bool FaceTracker::checkIfFolderIsEmpty(string path) const {

    char cmd[1024];
    int status, exitcode;

    char *folder = new char[path.length() + 1];
    std::strcpy(folder,path.c_str());

    snprintf(cmd, 1024, "test $(ls -A \"%s\" 2>/dev/null | wc -l) -ne 0", folder);

    status = system(cmd);
    exitcode = WEXITSTATUS(status);

    delete [] folder;

    ///the folder is empty
    if (exitcode == 1){
        return true;

    }else{
        return false;
    }

}

string FaceTracker::objectsDetection(const Mat& frame){

    cv_image<bgr_pixel> cimg(frame);

    // Detect faces
    std::vector<dlib::rectangle> faces = detector_(cimg);
    // Find the pose of each face.
    std::vector<full_object_detection> shapes;

    std::vector<cv::Rect> facesRects;

    Rect closestRectCenter;
    double  minDistRectCenter = 1000000;
    for (unsigned long i = 0; i < faces.size(); ++i){
        dlib:: rectangle r = faces[i];
        dlib::point tl = r.tl_corner();
        int x = tl.x();
        int y = tl.y();
        cv::Rect cvRect = Rect(x,y,r.width(),r.height());
        double distCenter =  sqrt(pow((cvRect.x - frame.cols), 2) +
                                  pow((cvRect.y - frame.rows), 2));
        if ( distCenter < minDistRectCenter){
            minDistRectCenter = distCenter;
            closestRectCenter = cvRect;
        }

        facesRects.push_back(cvRect);
      
    }


    std::vector<string> shirtsColors;

    for(int i = 0; i < facesRects.size(); i++ ){

        string shirtColor = detectShirtColor(facesRects[i],frame);
        shirtsColors.push_back(shirtColor);
    }

    string number = to_string(facesRects.size());

    if( facesRects.size() == 0){
        return "i dont see any faces right now ";
    }
    
    std::vector<string> shirtsDescription;

    if(  shirtsColors.size() == 1 ){
        shirtsDescription.push_back(shirtsColors[0]+" shirt ");
            
    } else {
         
        for(int i =0; i < shirtsColors.size(); i++){

            

            shirtsDescription.push_back(shirtsColors[i]);
            if(i !=  shirtsColors.size()- 1 ){
                shirtsDescription.push_back("shirt and "); 
            } else {
                shirtsDescription.push_back("shirt"); 
            }
        
        }

    }

   
    string finalDescription;
    std::for_each(shirtsDescription.begin(),shirtsDescription.end(), 
            [&](const std::string &piece){ finalDescription += piece; });


    return "i see "+number+" person with "+ finalDescription;



}

void FaceTracker::removeFacesDatabase(){

    cout<<" remove face databse func "<<endl;
    const char* path = "/home/intel/toibot_ws/src/ToiBot1/src/toi_bot_vision/faces";
    removeFolder(path);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    createFolderWithName("faces", "/home/intel/toibot_ws/src/ToiBot1/src/toi_bot_vision");



}




string FaceTracker::detectShirtColor(cv::Rect faceRect, const Mat& frame){
    
    ///debug
    Mat debug = frame.clone();

    int maxInRows =  frame.rows - faceRect.y + faceRect.height;

    cv::Rect shirtRoi = cv::Rect(faceRect.x,
                        faceRect.y+faceRect.height,
                        faceRect.width ,
                        maxInRows /2 );
    cv::rectangle(debug,shirtRoi,cv::Scalar(255,0,0),2,8,0);
 
    if( shirtRoi.x > 0 && shirtRoi.y > 0 
        &&  shirtRoi.x +  shirtRoi.width < frame.cols
        && shirtRoi.y +  shirtRoi.height < frame.rows){


            Mat crop  = frame(shirtRoi);
            cvtColor(crop,crop,COLOR_BGR2Lab);
            string color = findBestColor(crop);
            cout<<color<<endl;
            cv::putText(crop,color,
                cv::Point(crop.cols/2,crop.rows/2),1, 3, cv::Scalar(0,255,0),3,8);
            
   

            
            imshow("crop",crop);
            waitKey(1);

            return color;
        }


   


    return "unknown color ";




}

string FaceTracker::findBestColor(const Mat& crop){

    string colourNames [] = {"black"," Blue", /*"Dark blue"*/"black", "Dark brown", "brown", "green", "dark green", "orange",
            "pink","dark pink", /*"dark purple",*/ "red", "dark red", "yellow","white"};

    cv::Point3i blackLAB = cv::Point3i(1,128,128);
    cv::Point3i blueLAB = cv::Point3i(224,117,114);
    cv::Point3i DarkBlueLAB = cv::Point3i(82,207,20);
    cv::Point3i DarkBrownLAB = cv::Point3i(83,144,163);
    cv::Point3i brownLAB = cv::Point3i(115,135,152);
    cv::Point3i greenLAB = cv::Point3i(223,42,211);
    cv::Point3i darkGeenLAB = cv::Point3i(112,84,159);
    cv::Point3i orangeLAB = cv::Point3i(156,186,199);
    cv::Point3i pinkLAB = cv::Point3i(179,159,129);
    cv::Point3i darkPinkLAB = cv::Point3i(139,213,119);
    cv::Point3i darkPurpleLAB = cv::Point3i(77,185,92);
    cv::Point3i redLAB = cv::Point3i(119,200,184);
    cv::Point3i darkRedLAB = cv::Point3i(90,184,152);
    cv::Point3i yellowLAB = cv::Point3i(255,128,128);
    cv::Point3i whiteLAB = cv::Point3i(255,128,255);


    Point3i colorLab [] = {blackLAB,blueLAB,DarkBlueLAB,DarkBrownLAB,brownLAB,greenLAB,
       darkGeenLAB,orangeLAB,pinkLAB,darkPinkLAB,/*darkPurpleLAB,*/redLAB,darkRedLAB,yellowLAB,whiteLAB };

    int sizeColors = sizeof(colorLab)/sizeof(*colorLab);
    float scores[sizeColors];
    for(int i = 0; i < sizeColors; i++){
        scores[i] = 0;
    }

    
    double avgL;
    double sumL =0;

    double avgA;
    double sumA =0;

    double avgB;
    double sumB =0;
    

    for (int y = 0; y < crop.rows; ++y){
        for (int x = 0; x < crop.cols; ++x){
            int l = crop.at<cv::Vec3b>(y,x)[0];
            int a = crop.at<cv::Vec3b>(y,x)[1];
            int b = crop.at<cv::Vec3b>(y,x)[2];

            sumL = sumL + l;
            sumA = sumA + a;
            sumB = sumL + b;            
        }
    }
    
    avgL = sumL /double( crop.rows*crop.cols);
    avgA = sumA /double( crop.rows*crop.cols);
    avgB = sumB /double( crop.rows*crop.cols);

    //cout<<" avgL "<<avgL<<" avgA "<<avgA<<" avgB "<<avgB<<endl;

    for( int i = 0; i < sizeColors; i++){
                cv::Point3i color = colorLab[i];
                 double dist = sqrt(pow((color.x -avgL), 2) +
                                pow((color.y - avgA), 2) +
                                pow((color.z - avgB), 2));
                scores[i] = dist;


            }

    double minDiff = 1000000;
    int index;
    for(int i = 0; i < sizeColors; i++){
        if( scores[i] < minDiff){
            minDiff = scores[i];
            index = i; 
        }
    }

    return colourNames[index];



}





