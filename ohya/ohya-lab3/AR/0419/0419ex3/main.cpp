#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    vector<double> height(6), weight(6);
    for(int i = 0; i < 6; i++) {
        cout << i + 1 << "番目の生徒の身長[m]を入力してください:";
        cin >> height[i];
        cout << i + 1 << "番目の生徒の体重[kg]を入力してください:";
        cin >> weight[i];
    }
    
    for(int i = 0; i < 6; i++) {
        double bmi = weight[i] /(height[i] * height[i]);
        cout << i + 1 << "番目の生徒のBMIは" << bmi << "です．" << endl;
    }
    return 0;
}
