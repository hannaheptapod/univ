#include <iostream>
#include <opencv2/opencv.hpp>

void Gray(cv::Mat& imat, cv::Mat& omat) {
    int average = 0;
    for (int r = 0; r < imat.rows; r++) {
        for (int c = 0; c < imat.cols; c++) {
            average = (imat.at<cv::Vec3b> (r, c)[0] + imat.at <cv::Vec3b> (r, c)[1] + imat.at <cv::Vec3b> (r, c)[2]) / 3;
            omat.at<unsigned char> (r, c) = average;
        }
    }
}

int main() {
    cv::Mat mat = cv::imread("いちご.jpg");
    cv::Mat gray(mat.rows, mat.cols, CV_8UC1, cv::Vec3b(0, 0, 0));
    Gray(mat, gray);
    cv::imshow("mat", mat);
    cv::imshow("gray", gray);
    cv::imwrite("Gいちご.jpg", gray);
    cv::waitKey();
    return 0;
}