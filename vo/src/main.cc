#include <iostream>
#include "opencv2/opencv.hpp"
#include <opencv2/core/mat.hpp>
// #include <opencv2/highgui.hpp>

using std::cout;
using std::endl;

int main()
{
    cout << "OpenCV version : " << CV_VERSION << endl;

    /******** 1. get images or capture webcam  ********/

    cv::Mat img;
    cv::Mat R_final, t_final; //the final rotation and tranlation vectors
    cv::RNG rng(12345);

    char filename[200];
    sprintf(filename, "/home/hj/Data/frame_%0d.png", 0);

    //read the first two frames from the dataset
    // cv::Mat img_color = cv::imread(filename);

    // if ( !img_color.data ) { 
    //     std::cout<< " --(!) Error reading images " << std::endl; 
    //     return -1;
    // }

    // work with grayscale images
    // cvtColor(img_color, img, cv::COLOR_BGR2GRAY);

    double t = (double)cv::getTickCount();
    img = cv::imread(filename, cv::IMREAD_GRAYSCALE);
    t = ((double)cv::getTickCount() - t)/cv::getTickFrequency();

    cv::namedWindow("gray", cv::WINDOW_NORMAL);
    imshow("gray", img);
    char c = (char)cv::waitKey(0);
    if (c == 27) return 0;

    cout << " time passed in seconds: " << t << endl;


    /******** 2. undistort and extract feature, cv:Match feature********/ 
    double t2 = (double)cv::getTickCount();
    std::vector<cv::Point2f> corners;
    cv::goodFeaturesToTrack( img,
                        corners,
                        100, // maxCorner
                        0.01, // qualityLevel
                        10, // minDistance
                        cv::Mat(), // mask
                        3, // blockSize
                        3, // gradientSize
                        false, // useHarrisDetector
                        0.04 ); // k

    t2 = ((double)cv::getTickCount() - t2)/cv::getTickFrequency();
    cout << " time passed in seconds: " << t2 << endl;

    cout << "** Number of corners detected: " << corners.size() << endl;
    int radius = 4;
    for( size_t i = 0; i < corners.size(); i++ )
    {
        circle( img, corners[i], radius, cv::Scalar(rng.uniform(0,255), rng.uniform(0, 256), rng.uniform(0, 256)), cv::FILLED );
    }
    imshow("gray", img);
    c = (char)cv::waitKey(0);
    if (c == 27) return 0;

    /******** 3. feature cv:Matching and triangulation, get the 3D feature in local map ********/            


    /******** 4. select keyframe ********/ 
                 

    /******** 5. local BA, save them as a map ********/


    return 0;
}