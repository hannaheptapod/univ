#include <iostream>
#include <opencv2/opencv.hpp>
int main() {
    cv::Mat src = cv::imread("src.jpg", 1);
    cv::Mat srcYUV; cv::cvtColor(src, srcYUV, cv::COLOR_BGR2YCrCb);
    cv::Mat equalized[3];
    cv::split(srcYUV, equalized);
    cv::Mat dstY, dstYUV, dst;
    cv::equalizeHist(equalized[0], dstY);
    equalized[0] = dstY;
    cv::merge(equalized, 3, dstYUV);
    cv::cvtColor(dstYUV, dst, cv::COLOR_YCrCb2BGR);
    cv::imwrite("equalized.jpg", dst);
    return 0;
}