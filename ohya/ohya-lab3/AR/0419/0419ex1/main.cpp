#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    double height = 0;
    int weight = 0;
    
    cout << "身長[m]を入力してください:";
    cin >> height;
    cout << "体重[kg]を入力してください:";
    cin >> weight;
    
    double bmi = 0;
    
    bmi = weight /(height * height);
    cout << "あなたのBMIは" << bmi << "です" << endl;
    
    string message;
    
    if(bmi < 18.5) {
        message = "低体重";
    } else if(bmi < 25) {
        message = "普通体重";
    } else if(bmi < 30) {
        message = "肥満(1度)";
    } else if(bmi < 35) {
        message = "肥満(2度)";
    } else if(bmi < 40) {
        message = "肥満(3度)";
    } else {
        message = "肥満(4度)";
    }
    
    cout << "あなたは" << message << "です．" << endl;
}
