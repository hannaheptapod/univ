#include <opencv2/opencv.hpp>
void DetectFace(const cv::Mat& img, cv::Mat& dst, const std::string& cascade_file) { cv::CascadeClassifier cascade; //カスケード作成、見た通りOpenCVの型
dst = img.clone(); //出力に入力画像をコピー
cascade.load(cascade_file); //学習したデータを読み込み
std::vector<cv::Rect> faces; //顔の輪郭情報を格納
cascade.detectMultiScale(dst, faces, 1.1, 3, 0, cv::Size(20, 20)); //顔を検知
for (int i = 0; i < faces.size(); i++) {//検出した顔の数だけ、矩形を作成
cv::rectangle(dst, cv::Point(faces[i].x, faces[i].y), cv::Point(faces[i].x + faces[i].width, faces[i].y + faces[i].height),
cv::Scalar(0, 200, 0), 3); //cv::rectangle()は四角形を描く関数 }
}
int main() {
    cv::Mat img = cv::imread(“/Users/jink/Desktop/Programme/C++/ohya-lab3/0614/japan.jpg”);
    std::string file_name = "C:/Users/nukin/source/repos/haarcascade_frontalface_default.xml"; cv::Mat result;
    DetectFace(img, result, file_name);
    cv::imshow("元画像", img);
    cv::imshow("処理後", result);
    cv::waitKey(0);
    return 0;
}