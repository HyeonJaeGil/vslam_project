#include <iostream>
#include "opencv2/opencv.hpp"
// #include <opencv2/core/mat.hpp>



int main()
{
    
    /******** 1. get images or capture webcam  ********/

    cv::Mat img_left, img_right;
    cv::Mat R_final, t_final; //the final rotation and tranlation vectors

    double scale = 1.00;
    char filename1[200];
    char filename2[200];
    sprintf(filename1, "/home/hj/Datasets/KITTI_VO/00/image_2/%06d.png", 0);
    sprintf(filename2, "/home/hj/Datasets/KITTI_VO/00/image_2/%06d.png", 1);

    //read the first two frames from the dataset
    cv::Mat img_left_c = cv::imread(filename1);
    cv::Mat img_right_c = cv::imread(filename2);

    if ( !img_left_c.data || !img_right_c.data ) { 
        std::cout<< " --(!) Error reading images " << std::endl; 
        return -1;
    }

    // work with grayscale images
    cvtColor(img_left_c, img_left, cv::COLOR_BGR2GRAY);
    cvtColor(img_right_c, img_right, cv::COLOR_BGR2GRAY);


    /******** 2. undistort and extract feature, cv:Match feature********/ 


    /******** 3. feature cv:Matching and triangulation, get the 3D feature in local map ********/            


    /******** 4. select keyframe ********/ 
                 

    /******** 5. local BA, save them as a map ********/


    return 0;
}