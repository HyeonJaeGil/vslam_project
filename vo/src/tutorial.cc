#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;

using namespace cv;
int main()
{
    Mat M(200,200, CV_8UC3, Scalar(0,0,255)); // BGR ordered.
    imshow("Display window", M);
    int k = waitKey(0); // Wait for a keystroke in the window


    // channels, dimensions, depth
    int sz[3] = {20,10,3};
    Mat L(3,sz, CV_8UC(1), Scalar::all(0));
    cout << " L channels: " << L.channels() << " L dims: " << L.dims << " L depth: " << L.depth() << endl;


    // reshape and channel numbers
    Mat C = (Mat_<double>(3,3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
    cout << "C = " << endl << " " << C.channels() << endl << endl; 
    cout << "C (numpy)   = " << endl << format(C, Formatter::FMT_NUMPY ) << endl << endl;

    C = (Mat_<double>({0, -1, 0, -1, 5, -1, 0, -1, 0})).reshape(3,3);
    cout << "C = " << endl << " " << C.channels() << endl << endl;
    cout << "C (numpy)   = " << endl << format(C, Formatter::FMT_NUMPY ) << endl << endl;

    C = (Mat_<double>({0, -1, 0, -1, 5, -1, 0, -1, 0}));
    cout << "C = " << endl << " " << C.channels() << endl << endl;


    // Take a portion of a Mat and make new Mat
    Mat RowClone = C.row(1).clone();
    cout << "RowClone = " << endl << " " << RowClone << endl << endl;


    // show in different format
    Mat R = Mat(3, 3, CV_8UC3);
    randu(R, Scalar::all(0), Scalar::all(255));
    cout << "R = " << endl << " " << R << endl << endl;
    cout << "R (csv)     = " << endl << format(R, Formatter::FMT_CSV   ) << endl << endl;
    cout << "R (numpy)   = " << endl << format(R, Formatter::FMT_NUMPY ) << endl << endl;


    // cout vectors via Mat
    std::vector<float> v;
    v.push_back( (float)CV_PI);   v.push_back(2);    v.push_back(3.01f);
    cout << "Vector of floats via Mat = " << endl << Mat(v) << endl << endl;
    // cout << "Vector of floats = " << endl << v << endl << endl; // error: vector does not have << operator
    
    return 0;

}