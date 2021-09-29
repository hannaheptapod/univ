#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int f0 = 0;
    int f1 = 1;
    int f2 = 0;
    int days = 0;
    int sum = 0;
    
    while(sum < 1001) {
        f2 = f0 + f1;
        sum += f1;
        days++;
        cout << days << "日目は" << f1 << "円貯金して，合計金額は" << sum << "円になりました．" << endl;
        f0 = f1;
        f1 = f2;
    }
    
    cout << "合計金額が1000円を超えるのは" << days << "日目でした．" << endl;
    
    return 0;
}
