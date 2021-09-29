#include <iostream>
#include <opencv2/opencv.hpp>
#include <math.h>
#include <fstream>
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

vector<vector<double>> makeProtos(int m_num) {
    const int d_num = 7;
    const int i_amount = 100;
    const int m_amount = pow(m_num, 2);
    vector<vector<double>> protos(d_num, vector<double>(m_amount, 0));

    for (int d = 0; d < d_num; d++) {
        for (int n = 0; n < i_amount; n++) {
            vector<string> dies_name = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
            string img_name = "dies/" + dies_name[d] + to_string(n) + ".png";
            Mat img_dies_src = imread(img_name, 0);
            Mat img_dies;
            threshold(img_dies_src, img_dies, 127, 255, THRESH_BINARY);
            vector<double> dies_FV = makeFV(img_dies, m_num);
            for (int m = 0; m < m_amount; m++) protos[d][m] += dies_FV[m] / i_amount;
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

void writeCSV(vector<vector<int>> results, int m_num) {
    const int d_num = 7;
    ofstream ofs("result/" + to_string(m_num) + "-mesh.csv");
    ofs << -1 << ",";
    for (int i = 0; i < d_num; i++) {
        ofs << i << ",";
    }
    ofs << endl;
    for (int row = 0; row < d_num; row++) {
        ofs << row << ",";
        for (int col = 0; col < d_num; col++) {
            ofs << results[row][col] << ",";
        }
        ofs << endl;
    }
}

int main(int argc, char *argv[]) {
    const int d_num = 7;
    const int i_amount = 100;
    int m_num = stoi(argv[1]);
    vector<vector<double>> protos = makeProtos(m_num);
    vector<vector<int>> results(d_num, vector<int>(d_num, 0));
    for (int dies = 0; dies < d_num; dies++) {
        for (int n = 0; n < i_amount; n++) {
            vector<string> dies_name = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
            string test_name = "dies/" + dies_name[dies] + to_string(n) + ".png";
            Mat test_img_src = imread(test_name, 0);
            Mat test_img;
            threshold(test_img_src, test_img, 127, 255, THRESH_BINARY);
            vector<double> test = makeFV(test_img, m_num);
            double min_dist = -1;
            int ans = 0;
            for (int d = 0; d < d_num; d++) {
                double distance = euclidDistance(protos[d], test, m_num);
                if (min_dist == -1 || distance < min_dist) {
                    min_dist = distance;
                    ans = d;
                }
            }
            results[dies][ans]++;
        }
    }
    cout << "done." << endl;
    writeCSV(results, m_num);
    return 0;
}