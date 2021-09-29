#include <iostream>
#include <opencv2/opencv.hpp>
#include <math.h>
using namespace std;
using namespace cv;

vector<double> makeFV(Mat img, int m_num) {
    const int i_size = img.rows;
    const int m_size = i_size / m_num;
    const int m_amount = pow(m_num, 2);
    vector<double> feat_vec(m_amount);

    for (int m = 0; m < m_amount; m++) {
        Rect rect_mesh(m_size * (m % m_num), m_size * (m / m_num), m_size, m_size);
        feat_vec[m] = mean(Mat(img, rect_mesh))[0];
    }
    return feat_vec;
}

vector<double> makeTest(string src_name, int m_num) {
    Mat img_src = imread(src_name, 0);
    Mat img;
    threshold(img_src, img, 127, 255, THRESH_BINARY);
    vector<double> test = makeFV(img, m_num);
    return test;
}

vector<vector<double>> makeProtos(int m_num) {
    const int d_num = 10;
    const int i_size = 20;
    const int i_amount = 500;
    const int m_amount = pow(m_num, 2);
    vector<vector<double>> protos(d_num, vector<double>(m_amount, 0));
    Mat digits_src = imread("src/digits.png", 0);
    Mat digits;
    threshold(digits_src, digits, 127, 255, THRESH_BINARY_INV);

    for (int digit = 0; digit < d_num; digit++) {
        for (int n = 0; n < i_amount; n++) {
            Rect rect_img(i_size * (n % 100), i_size * (digit*5 + n/100), i_size, i_size);
            vector<double> FV_img = makeFV(Mat(digits, rect_img), m_num);
            for (int m = 0; m < m_amount; m++) {
                protos[digit][m] += FV_img[m] / i_amount;
            }
        }
    }
    return protos;
}

double euclidDistance(vector<double> proto, vector<double> test, int m_num) {
    const int m_amount = pow(m_num, 2);
    double distance = 0;

    for (int m = 0; m < m_amount; m++) {
        distance += pow(proto[m] - test[m], 2);
    }
    distance = pow(distance, 0.5);
    return distance;
}

int main(int argc, char *argv[]) {
    const int d_num = 10;
    string test_src = (string)argv[1];
    int m_num = stoi(argv[2]);
    vector<vector<double>> protos = makeProtos(m_num);
    vector<double> test = makeTest(test_src, m_num);
    double min_dist = -1;
    int ans = 0;
    for (int digit = 0; digit < d_num; digit++) {
        double distance = euclidDistance(protos[digit], test, m_num);
        cout << digit << " : " << distance << endl;
        if (min_dist == - 1 || distance < min_dist) {
            min_dist = distance;
            ans = digit;
        }
    }
    cout << "The closest character is " << ans << "." << endl;
    return 0;
}