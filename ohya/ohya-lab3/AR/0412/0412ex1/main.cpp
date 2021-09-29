//
//  main.cpp
//  0412homework
//
//  Created by Jin K on 2021-04-12.
//

#include <iostream>
#include <math.h>
using namespace std;

int main() {
    cout << "0〜100点の点数を入力してください．" << endl;
    
    int test[5] = {};
    for(int i = 0; i < 5;) {
        int score = 0;
        
        cout << i + 1 << "人目のテストの点数を入力してください:";
        cin >> score;
        if(score < 0 || score > 100) {
            cout << "入力された点数が間違っています．" << endl;
        } else {
            test[i + 1] = score;
            i++;
            
        }
    }
    
    int sum = 0;
    int sum2 = 0;
    
    for(int i = 0; i < 5; i++) {
        sum += test[i + 1];
        sum2 += test[i + 1] * test[i + 1];
    }
    
    double ave = 0.0;
    ave = (double)sum / 5;
    double stdev = 0.0;
    stdev = sqrt((double)sum2/5 - ave*ave);
    
    for(int i = 0; i < 5; i++) {
        double stdscore = 0.0;
        stdscore = 10 * (test[i + 1] - ave) / stdev + 50;
        
        cout << i + 1 << "人目の偏差値は" << stdscore << "です．" << endl;
    }
}
