#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace cv;

int main(int argc, char *argv[]) {
    Mat img = Mat::zeros(800, 800, CV_8UC3);
    circle(img, Point(200, 200), 80, Scalar(194, 133, 0), 3, 4);
    circle(img, Point(300, 300), 80, Scalar(50, 177, 251), 3, 4);
    circle(img, Point(400, 200), 80, Scalar(0, 0, 0), 3, 4);
    circle(img, Point(500, 300), 80, Scalar(60, 139, 28), 3, 4);
    circle(img, Point(600, 200), 80, Scalar(78, 51, 238), 3, 4);
    namedWindow("drawing");
    imshow("drawing", img);
    waitKey(0);
    return 0;
}