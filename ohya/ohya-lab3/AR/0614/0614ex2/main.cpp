#include <iostream>
#include <stack>
#include <opencv2/opencv.hpp>

int main() {
    cv::Vec2i print;

    std::stack<cv::Vec2i> data;
    data.push({6, 10});
    data.push({3, 0});
    data.push({4, 6});
    data.push({1, 25});

    while (!data.empty()) {
        print = data.top();
        data.pop();
        std::cout << print[0] << ", " << print[1] << std::endl;
    }
    return 0;
}