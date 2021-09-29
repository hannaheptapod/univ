#include <iostream>
#include <math.h>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

const int d_num = 10;

double euclidDist(vector<double> proto, vector<double> test) {
    double sum_square = 0;
    for (int i = 0; i < proto.size(); i++) {
        sum_square += pow(proto[i] - test[i], 2);
    }
    double distance = pow(sum_square, 0.5);
    return distance;
}

vector<vector<double>> makeProto(int mesh_num) {
    Mat digits_src = imread("src/digits.png", 0);
    Mat digits;
    threshold(digits_src, digits, 127, 255, ThresholdTypes::THRESH_BINARY_INV);

    const int n_num = 500;
    const int i_size = 20;
    int mesh_size = i_size / mesh_num;
    vector<vector<double>> protos(d_num, vector<double>(pow(mesh_num, 2)));
    bool flag_save = 0;
    string flag_save_char = "n";
    cout << "Save the image of prototype? (y / n):";
    cin >> flag_save_char;
    if (flag_save_char == "y") {
        flag_save = 1;
    }

    for (int digit = 0; digit < d_num; digit++) {
        vector<double> sum(pow(mesh_num, 2), 0);
        for (int num = 0; num < n_num; num++) {
            int num_general = n_num * digit + num;
            Rect rec_img(i_size*(num_general % 100), i_size*(num_general / 100), i_size, i_size);
            Mat img_digit(digits, rec_img);
            for (int m = 0; m < pow(mesh_num, 2); m++) {
                Rect mesh(mesh_size*(m % mesh_num), mesh_size*(m / mesh_num), mesh_size, mesh_size);
                Mat img_mesh(img_digit, mesh);
                sum[m] += mean(img_mesh)[0] / 255;
            }
        }
        if (flag_save == 1) {
            Mat proto_img(mesh_num, mesh_num, CV_8UC1);
            for (int row = 0; row < mesh_num; row++) {
            for (int col = 0; col < mesh_num; col++) {
                proto_img.at<uchar>(row, col) = sum[row*mesh_num + col]/(n_num/255);
            }
            }
            imwrite(to_string(digit)+".png", proto_img);

        }
        for (int m = 0; m < pow(mesh_num, 2); m++) {
            protos[digit][m] = sum[m] / n_num;
        }
    }
    return protos;
}

vector<double> makeTest(int mesh_num) {
    vector<double> test(pow(mesh_num, 2));
    string src_name;
    cout << "Input the name of test image:";
    cin >> src_name;
    Mat test_src = imread(src_name, 0);
    Mat img_test;
    threshold(test_src, img_test, 127, 255, CV_8UC1);
    const int img_size = 1800;
    int mesh_size = img_size / mesh_num;
    for (int m = 0; m < pow(mesh_num, 2); m++) {
        Rect mesh(mesh_size*(m % mesh_num), mesh_size*(m / mesh_num), mesh_size, mesh_size);
        Mat img_mesh(img_test, mesh);
        test[m] = mean(img_mesh)[0] / 255;
    }
    return test;
}

int main() {
    int mesh_num = 20;
    cout << "Input the number of mesh:";
    cin >> mesh_num;
    vector<vector<double>> proto = makeProto(mesh_num);

    for (int digit = 0; digit < d_num; digit++) {
        cout << "digit " << digit << endl;
        for (int m = 0; m < pow(mesh_num, 2); m++) {
            cout << proto[digit][m] << endl;
        }
    }
    vector<double> test = makeTest(mesh_num);
    for (int digit = 0; digit < d_num; digit++) {
        cout << digit << ":" << euclidDist(proto[digit], test) << endl;
    }
    return 0;
}