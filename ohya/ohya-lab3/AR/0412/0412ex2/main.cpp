#include <iostream>
using namespace std;

int main() {
    
    string cardStr;
    int cardInt[16];
    
    cout << "カード番号を入力してください:";
    cin >> cardStr;
    
    for(int i = 0; i < cardStr.length(); i++) {
        
        cardInt[i] = (int)(cardStr[i] - '0');
    }
    
    int sum = 0;
    int sumOfEven = 0;
    int sumOfOdd = 0;

    for(int i = 0; i < cardStr.length(); i++) {
        
        if(i % 2 == 0) {
            
            if(cardInt[i] < 5) {
                
                sumOfEven += 2 * cardInt[i];
                
            } else {
                
                sumOfEven += 2*cardInt[i] - 9;
            }
            
        } else {
            
            sumOfOdd += cardInt[i];
        }
    }
    
    sum = sumOfEven + sumOfOdd;
    
    //cout << sumOfEven << "+" << sumOfOdd << "=" << sum << endl;
    
    if(sum % 10 == 0) {
        
        cout << "正常です．" << endl;
        
    } else {
        
        cout << "異常です．" << endl;
    }
}
