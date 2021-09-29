#include <iostream>
#include <math.h>
#include <opencv2/opencv.hpp>
using std::vector;
using cv::Mat;

void printVec2(vector<vector<int>> vec) {
    for (int r = 0; r < vec[0].size(); r++) {
        for (int c = 0; c < vec[1].size(); c++) {
            std::cout << vec[r][c];
        }
        std::cout << std::endl;
    }
}

void printProto(vector<double> vec, int mesh = 1) {
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << std::endl;
    }
}

double euclidDist(vector<double> proto, vector<double> vec) {
    double distance = 0;
    for (int i = 0; i < proto.size(); i++) {
        distance += pow(proto[i] - vec[i], 2);
    }
    return pow(distance, 0.5);
}

vector<vector<double>> makeProto(int mesh) {
    Mat digits_src = cv::imread("digits.png", 0);
    Mat digits;
    cv::threshold(digits_src, digits, 127, 255, cv::ThresholdTypes::THRESH_BINARY_INV);

    vector<vector<vector<vector<int>>>> train_data(
        10, vector<vector<vector<int>>> (500, vector<vector<int>> (
                20, vector<int> (20))));
    
    vector<vector<vector<double>>> klass(
        10, vector<vector<double>> (
            500, vector<double> (pow(mesh, 2))));
    vector<vector<double>> prototype(10, vector<double>(pow(mesh, 2), 0.0));

    for (int digit = 0; digit < 10; digit++) {
        for (int num = 0; num < 500; num++) {
            const int row = (num / 100) * 20 + digit * 100, col = (num % 100) * 20;

            for (int r = 0; r < 20; r++) {
                for (int c = 0; c < 20; c++) {
                    int p = digits.at<uchar>(row + r, col + c) / 255;
                    train_data[digit][num][r][c] = p;
                    klass[digit][num][(r*mesh / 20) * mesh + (c*mesh / 20)] += p;
                }
            }

            for (int i = 0; i < pow(mesh, 2); i++) {
                klass[digit][num][i] /= 400.0 / (pow(mesh, 2));
                prototype[digit][i] += klass[digit][num][i];
            }
        }
        for (int i = 0; i < pow(mesh, 2); i++) {
            prototype[digit][i] /= 500.0;
        }
    }
    return prototype;
}

vector<double> makeTest(int mesh) {
    std::string src_name;
    std::cout << "Input the name of source file(20n x 20n):";
    std::cin >> src_name;
    Mat src_test = cv::imread(src_name, 0);
    Mat test;
    cv::threshold(src_test, test, 127, 255, cv::ThresholdTypes::THRESH_BINARY);
    vector<double> test_meshed(pow(mesh, 2));

    for (int i = 0; i < pow(mesh, 2); i++) {
        int mesh_size = test.rows / mesh;
        cv::Mat mesh_rec(test, cv::Rect(mesh_size*(i / mesh), mesh_size*(i % mesh), mesh_size, mesh_size));
        double sum = 0;
        for (int row = 0; row < mesh_size; row++) {
            for (int col = 0; col < mesh_size; col++) {
                sum += mesh_rec.at<uchar>(row, col) / 255;
            }
        }
        test_meshed[i] = sum / pow(mesh_size, 2);
    }

    return test_meshed;
}

int main() {
    int mesh = 20;
    std::cout << "Input the number of the mesh:";
    std::cin >> mesh;
    vector<vector<double>> prototype = makeProto(mesh);
    vector<double> test_meshed = makeTest(mesh);

    for (int digit = 0; digit < 10; digit++) {
        std::cout << digit << " = " << euclidDist(prototype[digit], test_meshed) << std::endl;
    }
}