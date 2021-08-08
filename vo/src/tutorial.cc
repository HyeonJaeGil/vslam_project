#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;

using namespace cv;

/*
[Result-Debug Mode]
Hand written function time passed in seconds: 0.00701735
Built-in filter2D time passed in seconds:     0.0101438

[Result-Release Mode]
Hand written function time passed in seconds: 0.00233336
Built-in filter2D time passed in seconds:     0.00104528
*/

void Sharpen(const Mat& myImage,Mat& Result);


int main( int argc, char* argv[])
{
    Mat src, dst0, dst1;
    if (argc >= 3 && !strcmp("G", argv[2]))
        src = imread( "/home/hj/Data/frame_2.png", IMREAD_GRAYSCALE);
    else
        src = imread( "/home/hj/Data/frame_2.png", IMREAD_COLOR);
    if (src.empty())
    {
        std::cerr << "Can't open image " << std::endl;
        return EXIT_FAILURE;
    }
    namedWindow("Input", WINDOW_AUTOSIZE);
    namedWindow("Output", WINDOW_AUTOSIZE);
    imshow( "Input", src );

    double t = (double)getTickCount();
    Sharpen( src, dst0 );
    t = ((double)getTickCount() - t)/getTickFrequency();
    cout << "Hand written function time passed in seconds: " << t << endl;
    imshow( "Output", dst0 );
    waitKey();
    
    Mat kernel = (Mat_<char>(3,3) <<  0, -1,  0,
                                   -1,  5, -1,
                                    0, -1,  0);
    t = (double)getTickCount();
    filter2D( src, dst1, src.depth(), kernel );
    t = ((double)getTickCount() - t)/getTickFrequency();
    cout << "Built-in filter2D time passed in seconds:     " << t << endl;
    imshow( "Output", dst1 );
    waitKey();
    return EXIT_SUCCESS;
}


void Sharpen(const Mat& myImage,Mat& Result)
{
    CV_Assert(myImage.depth() == CV_8U);  // accept only uchar images
    const int nChannels = myImage.channels();
    Result.create(myImage.size(),myImage.type());
    for(int j = 1 ; j < myImage.rows-1; ++j)
    {
        const uchar* previous = myImage.ptr<uchar>(j - 1);
        const uchar* current  = myImage.ptr<uchar>(j    );
        const uchar* next     = myImage.ptr<uchar>(j + 1);
        uchar* output = Result.ptr<uchar>(j);
        for(int i= nChannels;i < nChannels*(myImage.cols-1); ++i)
        {
            *output++ = saturate_cast<uchar>(5*current[i]
                         -current[i-nChannels] - current[i+nChannels] - previous[i] - next[i]);
        }
    }
    Result.row(0).setTo(Scalar(0));
    Result.row(Result.rows-1).setTo(Scalar(0));
    Result.col(0).setTo(Scalar(0));
    Result.col(Result.cols-1).setTo(Scalar(0));
}