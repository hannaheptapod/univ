#include <iostream>
#include <stack>
#include <opencv2/opencv.hpp>

cv::Vec3b GetPixel(cv::Mat& imat, int ix, int iy) {
    if (ix >= 0 && ix < imat.cols && iy >= 0 && iy < imat.rows) return imat.at<cv::Vec3b>(iy, ix);
    else return cv::Vec3b(0, 0, 0);
}
void DrawPixel(cv::Mat& imat, int ix, int iy, cv::Vec3b icolor) {
    imat.at<cv::Vec3b>(iy, ix) = icolor;
}
bool isinArea(cv::Mat& imat, int ix, int iy) {
    if (ix <= 0 && ix < imat.cols && iy >= 0 && iy < imat.rows) return true;
    else return false;
}
void Bucket(cv::Mat& imat, int ix, int iy, cv::Vec3b icolor) {
    cv::Vec3b bucket_color = GetPixel(imat, ix, iy);
    cv::Vec2i tmp;
    std::cout << "start" << std::endl;
    std::stack<cv::Vec2i> bucket_stack;
    bucket_stack.push({ix, iy});
    while (!bucket_stack.empty()) {
        tmp = bucket_stack.top(); bucket_stack.pop();
        DrawPixel(imat, tmp[0], tmp[1], icolor);
        if (isinArea(imat, tmp[0] - 1, tmp[1]) && GetPixel(imat, tmp[0] - 1, tmp[1]) == bucket_color) bucket_stack.push({tmp[0] - 1, tmp[1]});
        if (isinArea(imat, tmp[0], tmp[1] - 1) && GetPixel(imat, tmp[0] + 1, tmp[1]) == bucket_color) bucket_stack.push({tmp[0] + 1, tmp[1]});
        if (isinArea(imat, tmp[0], tmp[1] - 1) && GetPixel(imat, tmp[0], tmp[1] - 1) == bucket_color) bucket_stack.push({tmp[0], tmp[1] - 1});
        if (isinArea(imat, tmp[0], tmp[1] + 1) && GetPixel(imat, tmp[0], tmp[1] + 1) == bucket_color) bucket_stack.push({tmp[0], tmp[1] + 1});
    }
    std::cout << "finish" << std::endl;
}

int main() {
    cv::Mat img = cv::imread("/Users/jink/Desktop/Programme/C++/ohya-lab3/0614/test.png");
    int ix, iy = 0;
    std::cout << "どこを始点にする？" << std::endl;
    std::cout << "範囲，ｘは" << img.cols << ", yは" << img.rows << "まで" << std::endl;
    std::cin >> ix >> iy;
    Bucket(img, ix, iy , cv::Vec3b(255, 0, 255));
    cv::imshow("result", img);
    cv::waitKey(0);
    return 0;
}