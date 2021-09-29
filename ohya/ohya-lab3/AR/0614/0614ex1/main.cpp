#include <iostream>
#include <list>
#include <vector>
//#include <opencv2/opencv.hpp>

int main() {
    std::list<std::string> data;

    data.push_back("急に");
    data.push_back("暑くなりすぎ");
    data.push_back("最近");

    std::list<std::string>::iterator itr;

    for (itr = data.begin(); itr != data.end(); itr++) std::cout << *itr << std::endl;

    itr = data.begin();
    itr++;
    data.insert(itr, "ホント");

    std::cout << std::endl;

    for (itr = data.begin(); itr != data.end(); itr++) std::cout << *itr << std::endl;

    return 0;
}