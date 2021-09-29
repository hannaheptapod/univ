#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int f0 = 0;
    int f1 = 1;
    int f2 = 0;
    int sum = 0;
    int days = 0;
    
    for(int i = 1; sum < 1001; i++) {
        f2 = f0 + f1;
        sum += f2;
        
        cout << i << "日目は" << f1 << "円貯金して，合計金額は" << sum << "円になりました．" << endl;
        
        f0 = f1;
        f1 = f2;
        days = i;
    }
    
    cout <<"合計金額が1000円を超えるのは" << days << "日目です．" << endl;
    
    return 0;
}
