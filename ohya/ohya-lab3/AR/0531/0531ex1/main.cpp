#include <opencv2/opencv.hpp>

using namespace cv;

int main() {
    Mat mat = imread("いちご.jpg");
    imshow("mat", mat);
    imwrite("いちごcopy.jpg", mat);
    waitKey(0);
    return 0;
}