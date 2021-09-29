#include <iostream>
#include <opencv2/opencv.hpp>
int main() {
    cv::Mat src, srcGray;
    src = cv::imread("src.jpg", 1);
    cv::cvtColor(src, srcGray, cv::COLOR_BGR2GRAY);
    cv::imwrite("Gray.jpg", srcGray);
    return 0;
}