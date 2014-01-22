
//ros dependencies
#include "ball_detector_node.h"

//node main
int main(int argc, char **argv)
{
      //init ros
      ros::init(argc, argv, "btr_ball_detector_node");
      
      //create ros wrapper object
      CballDetectorNode detector;
      
      //set node loop rate
      ros::Rate loop_rate(30);
      
      //node loop 
      while ( ros::ok() )
      {
            //if new image , do things
            if ( detector.newImage() )
            {
                  detector.process();
                  detector.publish();
            }
            
            //execute pending callbacks
            ros::spinOnce(); 
      }
            
      //exit program
      return 0;
}