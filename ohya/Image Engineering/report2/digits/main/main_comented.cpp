#include <iostream>
#include <opencv2/opencv.hpp>
#include <math.h>
#include <fstream>
using namespace std;
using namespace cv;
vector<double> makeFV(Mat img, int m_num);//特徴ベクトル計算
vector<vector<double>> makeProtos(int m_num);//各クラスのプロトタイプ計算
Mat cutDigit(int digit, int n);//digits.pngからテスト画像切り出し
double euclidDistance(vector<double> proto, vector<double> test, int m_num);//ユークリッド距離計算
void writeCSV(vector<vector<int>> results, int m_num);//認識実験結果出力
int main(int argc, char *argv[]) {
    const int d_num = 10;//数字の種類 (0~9)
    const int i_amount = 500;//各クラスに属するパターン数
    int m_num = stoi(argv[1]);//メッシュのブロック数 (正方形ブロックの行・列数)
    vector<vector<double>> protos = makeProtos(m_num);
    vector<vector<int>> results(d_num, vector<int>(d_num, 0));
    for (int digit = 0; digit < d_num; digit++) {
        for (int n = 0; n < i_amount; n++) {
            if (n % 100 == 0) cout << digit*i_amount + n << "/5000 calculated..." << endl;
            vector<double> test = makeFV(cutDigit(digit, n), m_num);
            double min_dist = -1;//距離の最小値を格納
            int ans = 0;//テスト画像に最近のクラス
            for (int d = 0; d < d_num; d++) {
                double distance = euclidDistance(protos[d], test, m_num);
                if (min_dist == -1 || distance < min_dist) {
                    min_dist = distance;
                    ans = d;
                }
            }
            results[digit][ans]++;//計算結果格納
        }
    }
    cout << "5000/5000 done." << endl;
    writeCSV(results, m_num);
    return 0;
}
vector<double> makeFV(Mat img, int m_num) {
    const int i_size = img.rows; 
    const int m_size = i_size / m_num;//メッシュのブロックサイズ (正方形ブロックの一辺長)
    const int m_amount = pow(m_num, 2);//メッシュブロックの総数
    vector<double> feat_vec(m_amount);//特徴ベクトル
    for (int m = 0; m < m_amount; m++) {
        Rect rect_mesh(m_size * (m % m_num), m_size * (m / m_num), m_size, m_size);
        feat_vec[m] = mean(Mat(img, rect_mesh))[0];//メッシュブロック内の面積率
    }
    return feat_vec;
}
vector<vector<double>> makeProtos(int m_num) {
    const int d_num = 10;
    //digits.pngには20x20の画像が各数字ごとに500枚ずつ入っている
    const int i_size = 20;
    const int i_amount = 500;
    const int m_amount = pow(m_num, 2);
    vector<vector<double>> protos(d_num, vector<double>(m_amount, 0));
    Mat digits_src = imread("src/digits.png", 0);
    Mat digits;
    //digits.pngは白文字黒背景で描かれているので反転しつつ2値化
    threshold(digits_src, digits, 127, 255, THRESH_BINARY_INV);
    //500枚の画像それぞれについて特徴ベクトルを計算，それらの重心をプロトタイプとする
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
Mat cutDigit(int digit, int n) {
    const int i_size = 20;
    Mat digits_src = imread("src/digits.png", 0);
    Mat digits;
    threshold(digits_src, digits, 127, 255, THRESH_BINARY_INV);
    Rect rect_img(i_size * (n % 100), i_size * (digit*5 + n/100), i_size, i_size);
    return Mat(digits, rect_img);
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
    const int d_num = 10;
    ofstream ofs("result/" + to_string(m_num) + "-mesh.csv");
    for (int row = 0; row < d_num; row++) {
        ofs << row << ",";
        for (int col = 0; col < d_num; col++) {
            ofs << results[row][col] << ",";
        }
        ofs << endl;
    }
}