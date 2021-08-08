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

// Declare the variables
Mat src, dst;
int top, bottom, left, right;
int borderType = BORDER_CONSTANT;
const char* window_name = "copyMakeBorder Demo";
RNG rng(12345);

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

    Point2f srcTri[3];
    srcTri[0] = Point2f( 0.f, 0.f );
    srcTri[1] = Point2f( src.cols - 1.f, 0.f );
    srcTri[2] = Point2f( 0.f, src.rows - 1.f );
    Point2f dstTri[3];
    dstTri[0] = Point2f( 0.f, src.rows*0.33f );
    dstTri[1] = Point2f( src.cols*0.85f, src.rows*0.25f );
    dstTri[2] = Point2f( src.cols*0.15f, src.rows*0.7f );
    Mat warp_mat = getAffineTransform( srcTri, dstTri );
    Mat warp_dst = Mat::zeros( src.rows, src.cols, src.type() );
    warpAffine( src, warp_dst, warp_mat, warp_dst.size() );
    Point center = Point( warp_dst.cols/2, warp_dst.rows/2 );
    double angle = -50.0;
    double scale = 0.6;
    Mat rot_mat = getRotationMatrix2D( center, angle, scale );
    Mat warp_rotate_dst;
    warpAffine( warp_dst, warp_rotate_dst, rot_mat, warp_dst.size() );
    imshow( "Source image", src );
    imshow( "Warp", warp_dst );
    imshow( "Warp + Rotate", warp_rotate_dst );
    waitKey();
    return 0;
}
