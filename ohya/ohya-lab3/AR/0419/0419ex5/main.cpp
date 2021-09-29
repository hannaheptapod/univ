#include <iostream>
#include <vector>
using namespace std;

//フィボナッチ数を返す関数
int fibonacci(int n) {
    
    if(n > 0) {
        int f0 = 0;
        int f1 = 1;
        int f2 = 0;
        
        for(int i = 1; i < n; i++) {
            f2 = f0 + f1;
            f0 = f1;
            f1 = f2;
        }
        return f1;
    } else {
        return 0;
    }
}

int main(int argc, const char * argv[]) {
    
    int numOfStep,numOfHole = 0;
    int numOfRoute = 1;
    
    
    cout << "段数を入力:";
    cin >> numOfStep;
    cout << "穴の数を入力:";
    cin >> numOfHole;
    vector<int> holePositions(numOfHole);
    //穴が0個の場合は (段数 + 1) 番目のフィボナッチ数を出力
    if(numOfHole == 0) {
        numOfRoute *= fibonacci(numOfStep + 1);
    } else {
        cout << numOfHole << "個の穴の位置を順に入力:";
        
        for(int i = 0; i < numOfHole; i++) {
            cin >> holePositions[i];
            
            //スタート・ゴールに穴が置かれた場合は0を出力
            if(holePositions[i] == 0 || holePositions[i] == numOfStep) {
                numOfRoute *= 0;
            }
        }
        //最初の穴までの道順
        numOfRoute *= fibonacci(holePositions[0] + 1);
        
        //穴と穴の間は，その間隔に合わせたフィボナッチ数を道順に掛ける
        for(int i = 1; i < numOfHole; i++) {
            int distance = 0;
            distance = holePositions[i] - holePositions[i - 1];
            
            //2個の穴が連続する場合は0を出力
            if(distance == 1) {
                numOfRoute *= 0;
            } else {
                numOfRoute *= fibonacci(distance);
            }
        }
        //最後の穴からの道順
        numOfRoute *= fibonacci(numOfStep - holePositions[numOfHole - 1] + 1);
    }
    cout << "ルートは全部で" << numOfRoute << "通りです．" << endl;
    return 0;
}
