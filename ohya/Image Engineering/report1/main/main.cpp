#include <iostream>
#include <opencv2/opencv.hpp>
using std::cout; using std::cin; using std::endl; using std::string;
using namespace cv;

void linearStretchColor(const Mat src, Mat& dst);//カラー画像の線形変換
void linearStretchGray(const Mat srcGray, Mat& dst);//モノクロ画像の線形変換
void histgramEqualizeColor(const Mat src, Mat& dst);//カラー画像のヒストグラム平坦化
void histgramEqualizeGray(const Mat srcGray, Mat& dst);//モノクロ画像のヒストグラム平坦化
Mat createHistgramColor(const Mat imageColor);//カラー画像のヒストグラム作成
Mat createHistgramGray(const Mat imageGray);//モノクロ画像のヒストグラム作成

int main() {
    string srcName;//source画像の名前
    Mat src, srcGray, dstEnColor, dstEnGray, dstEqColor, dstEqGray;//各画像
    Mat srcVec[3];//source画像を3チャンネルに分割したもの
    split(src, srcVec);//source画像を分割する
    cout << "Input Source Image:"; cin >> srcName;//source画像をコンソールで指定

    src = imread(srcName, 1);//imreadでsource画像を読み込む（カラー）
    cvtColor(src, srcGray, COLOR_BGR2GRAY);//source画像をグレースケール化
    imshow("src", src); //source画像を表示
    imshow("srcHist", createHistgramColor(src));//ヒストグラム表示
    imshow("srcGray", srcGray); //source画像（モノクロ）
    imshow("srcGrayHist", createHistgramGray(srcGray));//ヒストグラム表示

    linearStretchColor(src, dstEnColor);//source画像に対して線形濃度変換
    linearStretchGray(srcGray, dstEnGray);//線形濃度変換（モノクロ）
    histgramEqualizeColor(src, dstEqColor);//source画像に対してヒストグラム平坦化
    histgramEqualizeGray(srcGray, dstEqGray);//ヒストグラム平坦化（モノクロ）

    imshow("Stretched - Color", dstEnColor);//結果表示用
    imshow("StretchedHist", createHistgramColor(dstEnColor));//
    imshow("Stretched - Gray", dstEnGray);//
    imshow("StretchedGrayHist", createHistgramGray(dstEnGray));//
    imshow("Equalized - Color", dstEqColor);//
    imshow("EqualizedHist", createHistgramColor(dstEqColor));//
    imshow("Equalized - Gray", dstEqGray);//
    imshow("EqualizedGrayHist", createHistgramGray(dstEqGray));//
    waitKey(0);
    imwrite(srcName + "Hist.jpg", createHistgramColor(src));//
    imwrite(srcName + "HistGray.jpg", createHistgramGray(srcGray));//
    imwrite(srcName + "Stretched.jpg", dstEnColor);//
    imwrite(srcName + "StretchedHist.jpg", createHistgramColor(dstEnColor));//
    imwrite(srcName + "StretchedGray.jpg", dstEnGray);//
    imwrite(srcName + "StretchedGrayHist.jpg", createHistgramGray(dstEnGray));//
    imwrite(srcName + "Equalized.jpg", dstEqColor);//
    imwrite(srcName + "EqualizedHist.jpg", createHistgramColor(dstEqColor));//
    imwrite(srcName + "EqualizedGray.jpg", dstEqGray);//
    imwrite(srcName + "EqualizedGrayHist.jpg", createHistgramGray(dstEqGray));//
    return 0;
}

void linearStretchColor(const Mat src, Mat& dst) {
    Mat dstVec[3];//チャンネルごとに分割したもの
    split(src, dstVec);//分割
    
    double lowG = 0.0; double highG = 255.0;//出力画像の最小濃度及び最大濃度（デフォルト）
    cout << endl << "線形変換 Color" << endl;//コンソールで出力濃度範囲を指定
    cout << "Input lowG.:";//
    cin >> lowG;//
    cout << "Input highG.:";//
    cin >> highG;//

    for (int ch = 0; ch < src.channels(); ch++) {//各チャンネルに対して処理を行う
        double minVal, maxVal;//入力画像の最小濃度及び最大濃度
        minMaxLoc(dstVec[ch], &minVal, &maxVal);//濃度範囲を計算
        for (int r = 0; r < dstVec[ch].rows; r++) {//各画素に対して繰り返し処理
            for (int c = 0; c < dstVec[ch].cols; c++) {
                int val;//入出力の濃度範囲を対応させ，線形補間
                val = dstVec[ch].data[r * dstVec[ch].step + c] - minVal;//
                val *= highG - lowG;//
                val /= maxVal - minVal;//
                val += lowG;//
                if (val < 0.0) val = 0.0;//濃度が0~255の範囲にない場合に修正する
                else if (val > 255.0) val = 255.0;//
                dstVec[ch].data[r * dstVec[ch].step + c] = val;//計算結果を代入
            }
        }
    }
    merge(dstVec, 3, dst);//チャンネルごとに分割して処理したものを出力先にマージ
}
void linearStretchGray(const Mat srcGray, Mat& dst) {//linearStretchColorと同様
    dst = srcGray.clone();
    double val, minVal, maxVal;
    double lowG = 0.0; double highG = 255.0;

    cout << endl << "線形変換 Gray" << endl;
    cout << "Input lowG.:";
    cin >> lowG;
    cout << "Input highG.:";
    cin >> highG;
    minMaxLoc(dst, &minVal, &maxVal);
    for (int r = 0; r < dst.rows; r++) {
        for (int c = 0; c < dst.cols; c++) {
            val = dst.data[r * dst.step + c] - minVal;
            val *= highG - lowG;
            val /= maxVal - minVal;
            val += lowG;
            if (val < 0.0) val = 0.0;
            else if (val > 255.0) val = 255.0;
            dst.data[r * dst.step + c] = val;
        }
    }
}//
void histgramEqualizeColor(const Mat src, Mat& dst) {
    Mat dstVec[3];//チャンネルごとに分割したもの
    split(src, dstVec);//分割
    for (int ch = 0; ch < src.channels(); ch++) {//チャンネルごとに処理
        equalizeHist(dstVec[ch], dstVec[ch]);//ヒストグラム平坦化
    }
    merge(dstVec, 3, dst);//出力先にマージ
}
void histgramEqualizeGray(const Mat srcGray, Mat& dst) {
    equalizeHist(srcGray, dst);//ヒストグラム平坦化
}
Mat createHistgramColor(const Mat imageColor) {
    Mat channels[3];//チャンネルごとに分割したもの
    split(imageColor, channels);//分割
    Mat imageHist;//ヒストグラム画像
    Mat B, G, R;//チャンネルごとのヒストグラム
    int histSize = 256;//ビンのサイズ
    float range[] = {0, 256};//計測する画素値の範囲
    const float* histRange = range;//

    calcHist(&channels[0], 1, 0, Mat(), B, 1, &histSize, &histRange);//チャンネルごとにヒストグラムを計算
    calcHist(&channels[1], 1, 0, Mat(), G, 1, &histSize, &histRange);//
    calcHist(&channels[2], 1, 0, Mat(), R, 1, &histSize, &histRange);//

    normalize(B, B, 0.0, 1.0, NORM_MINMAX, -1, Mat());//ヒストグラムを正規化
    normalize(G, G, 0.0, 1.0, NORM_MINMAX, -1, Mat());//
    normalize(R, R, 0.0, 1.0, NORM_MINMAX, -1, Mat());//

    imageHist = Mat(Size(276,320), CV_8UC3, Scalar(255, 255, 255));//ヒストグラム画像を作成

    for(int i = 0; i < 3; i++) rectangle(
        imageHist, //背景をグレーに
        Point(10, 10 + 100 * i), //
        Point(265, 100 + 100 * i), //
        Scalar(230, 230, 230), -1);//

    for(int i = 0; i < 256; i++) {
        line(imageHist,//青
            Point(10 + i, 300),//
            Point(10 + i, 300 - (int)(B.at<float>(i) * 80)),//
            Scalar(255, 0, 0), 1, 8, 0);//
        line(imageHist,//緑
            Point(10 + i, 200),//
            Point(10 + i, 200 - (int)(G.at<float>(i) * 80)),//
            Scalar(0, 255, 0), 1, 8, 0);//
        line(imageHist,//赤
            Point(10 + i, 100),//
            Point(10 + i, 100 - (int)(R.at<float>(i) * 80)),//
            Scalar(0, 0, 255), 1, 8, 0);//

        if(i % 10 == 0) {//補助目盛線
            line(imageHist, Point(10 + i, 300), Point(10 + i, 210), Scalar(170, 170, 170), 1, 8, 0);//
            line(imageHist, Point(10 + i, 200), Point(10 + i, 110), Scalar(170, 170, 170), 1, 8, 0);//
            line(imageHist, Point(10 + i, 100), Point(10 + i, 10), Scalar(170, 170, 170), 1, 8, 0);//
            if(i % 50 == 0) {//目盛線
                line(imageHist, Point(10 + i, 300), Point(10 + i, 210), Scalar(50, 50, 50), 1, 8, 0);//
                line(imageHist, Point(10 + i, 200), Point(10 + i, 110), Scalar(50, 50, 50), 1, 8, 0);//
                line(imageHist, Point(10 + i, 100), Point(10 + i, 10), Scalar(50, 50, 50), 1, 8, 0);//
            }
        }
    }
    return imageHist;
}
Mat createHistgramGray(const Mat imageGray) {//createHistgramColorと同様
    Mat imageHist;
    Mat hist;
    int histSize = 256;
    float range[] = {0, 256};
    const float* histRange = range;
    calcHist(&imageGray, 1, 0, Mat(), hist, 1, &histSize, &histRange);

    normalize(hist, hist, 0.0, 1.0, NORM_MINMAX, -1, Mat());

    imageHist = Mat(Size(276, 120), CV_8UC3, Scalar(255, 255, 255));
  
    rectangle(imageHist, Point(10, 10), Point(265, 100), Scalar(230, 230, 230), -1);

    for(int i = 0; i < 256; i++) {
        line(imageHist,
            Point(10 + i, 100),
            Point(10 + i, 100 - (int)(hist.at<float>(i) * 80)),
            Scalar(10, 10, 10), 1, 8, 0);

        if(i % 10 == 0) {
            line(imageHist, Point(10 + i, 100), Point(10 + i, 10), Scalar(170, 170, 170), 1, 8, 0);
            if(i % 50 == 0) line(imageHist, Point(10 + i, 100), Point(10 + i, 10), Scalar(50, 50, 50), 1, 8, 0);
        }
    }
    return imageHist;
}//