
#include "/home/intel/toibot_ws/src/ToiBot1/src/toi_bot_vision/include/toi_bot_vision/visionRos.h"



using namespace dlib;
using namespace std;




void visionRos::visionCallbackCommand(const toi_bot_vision::visionMsgCommand& msg){



    state_ = static_cast<visionState>(msg.visionStateCommand);

    name_ =  msg.personName;

    cout<<"get msg "<<state_<<" and name "<<name_<<endl;



}

void visionRos::convertVisionStructToMsg(toi_bot_vision::visionMsgOutput& m, VisionOutputForManager visionOutput){

    m.canRecognize = visionOutput.canRecognize;
    m.deltaX = visionOutput.deltaX ;
    m.deltaY = visionOutput.deltaY;
    m.detectFace = visionOutput.detectFace;
    m.emotion = visionOutput.emotion;
    m.name =  visionOutput.name;

}

void visionRos::initSystem(){

    if( init_ == false ){

        visionPublisher_ = node_.advertise<toi_bot_vision::visionMsgOutput>(
                "vision_publisher_output", 1, true);

        visonSubCommand_ = node_.subscribe( "vision_publisher_command", 1,  &visionRos::visionCallbackCommand, this);

        init_ = true;

    }
}

visionRos::visionRos(){


    initSystem();

    while(ros::ok()){



        cv::Mat frame;
        cap >> frame;

        if( state_ == init){
            state_ = tracking;
        }

        if( state_ == tracking ){

            VisionOutputForManager visionOutput = personManager_.track(state_,frame);

            if( state_ == recognition){

                cout<<" iniside recognition "<<endl;

                VisionOutputForManager visionOutputRecognize = personManager_.recognize(state_,frame);
                visionOutput.name = visionOutputRecognize.name;



                cv::putText(frame,visionOutput.name,
                            cv::Point(frame.rows/2,frame.cols/2),1, 3, cv::Scalar(0,255,0),3,8);
                imshow("frame",frame);
                waitKey(1);

                toi_bot_vision::visionMsgOutput m;
                convertVisionStructToMsg(m,visionOutput);
                visionPublisher_.publish(m);



                 state_ = tracking;

            } else {


                toi_bot_vision::visionMsgOutput m;
                convertVisionStructToMsg(m,visionOutput);
                visionPublisher_.publish(m);

                state_ = tracking;
            }





        }
        if( state_ == memorization){
            cout<<" iniside remember me "<<endl;

            personManager_.rememberMe(state_,name_, frame);
            state_ = tracking;


        }

        if( state_ == emotionRecognition){

            VisionOutputForManager visionMsgOutputEmotion = personManager_.detectEmotion(state_, frame);

            cv::putText(frame,visionMsgOutputEmotion.emotion,
                        cv::Point(frame.rows/2,frame.cols/2),1, 3, cv::Scalar(0,255,0),3,8);
            imshow("frame",frame);
            waitKey(1);
            state_ = tracking;

            toi_bot_vision::visionMsgOutput m;
            convertVisionStructToMsg(m,visionMsgOutputEmotion);
            visionPublisher_.publish(m);

         }

         ros::spinOnce();

    }



}

