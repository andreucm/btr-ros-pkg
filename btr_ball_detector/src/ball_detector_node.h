
//std
#include <string>

//external lib
#include "ballDetector.h"

//ros dependencies
#include "ros/ros.h"
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include "sensor_msgs/CameraInfo.h"
#include <sensor_msgs/image_encodings.h>
#include <btr_ball_detector/circleSetStamped.h>
#include <btr_ball_detector/detectorParamsConfig.h>

/** \brief wrapping class
 * 
 * Wraps ballDetector object and implement ROS comm's
 * 
 **/
class CballDetectorNode
{
      protected:
            
            //ball_detector library object
            CballDetector detector;
            
            //ros node handle
            ros::NodeHandle nh;
            
            //image publisher/subscriber
            image_transport::ImageTransport it;
            image_transport::Publisher imagePub;            
            cv_bridge::CvImage cvImgPub;
            image_transport::Subscriber imageSubs;            
            cv_bridge::CvImagePtr cvImgPtrSubs;            

            //circle set publisher
            btr_ball_detector::circleSetStamped circlesMsg;            
            ros::Publisher circlesPub;
            
            //camera info subscriber
            sensor_msgs::CameraInfo cameraInfoMsg;
            ros::Subscriber cameraInflSubs;

            //dynamic reconfigure 
            btr_ball_detector::detectorParamsConfig config; 
            
            //flag indicating a new image has been received
            bool newImageFlag;
            
            //image time stamp
            unsigned int tsec;
            unsigned int tnsec;
            
            //img encoding id
            unsigned int imgEncoding;
            
            
      public:
            CballDetectorNode();
            ~CballDetectorNode();
            
            bool newImage();
            void process();            
            void publishImage();
            void publishCircles();
            void imageCallback(const sensor_msgs::ImageConstPtr & msg);
            void cameraInfoCallback(const sensor_msgs::CameraInfo & msg);
};
