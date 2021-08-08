#include <iostream>
#include "opencv2/opencv.hpp"
#include <opencv2/core/mat.hpp>



int main()
{
    
    /******** 1. get images or capture webcam  ********/

    cv::Mat img;
    cv::Mat R_final, t_final; //the final rotation and tranlation vectors

    char filename[200];
    sprintf(filename, "/home/hj/Data/frame_%0d.png", 0);

    //read the first two frames from the dataset
    cv::Mat img_color = cv::imread(filename);

    if ( !img_color.data ) { 
        std::cout<< " --(!) Error reading images " << std::endl; 
        return -1;
    }

    // work with grayscale images
    cvtColor(img_color, img, cv::COLOR_BGR2GRAY);

    imshow("gray", img);
    char c = (char)cv::waitKey(2000);
    if (c == 27) return 0;


    /******** 2. undistort and extract feature, cv:Match feature********/ 


    /******** 3. feature cv:Matching and triangulation, get the 3D feature in local map ********/            


    /******** 4. select keyframe ********/ 
                 

    /******** 5. local BA, save them as a map ********/


    return 0;
}