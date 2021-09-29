#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
void Gray(Mat& imat, Mat& omat) {
    int average = 0;
    for (int r = 0; r < imat.rows; r++) {
        for (int c = 0; c < imat.cols; c++) {
            average = (imat.at<Vec3b> (r, c)[0] + imat.at <Vec3b> (r, c)[1] + imat.at <Vec3b> (r, c)[2]) / 3;
            omat.at<unsigned char> (r, c) = average;
        }
    }
}

void Binary(Mat& imat, Mat& omat, int threshold) {
    for (int r = 0; r < imat.rows; r++) {
        for (int c = 0; c < imat.cols; c++) {
            if (imat.at <unsigned char> (r, c) < threshold) omat.at <unsigned char> (r, c) = 255;
            else omat.at <unsigned char> (r, c) = 0;
        }
    }
}

int main() {
    Mat mat = imread("いちご.jpg");
    Mat gray(mat.rows, mat.cols, CV_8UC1, Vec3b(0, 0, 0));
    Mat bin(mat.rows, mat.cols, CV_8UC1, Vec3b(0, 0, 0));
    Gray(mat, gray);
    imshow("gray", gray);
    Binary(gray, bin, 64);
    imshow("64", bin);
    Binary(gray, bin, 128);
    imshow("128", bin);
    Binary(gray, bin, 192);
    imshow("192", bin);
    waitKey();
    return 0;
}

