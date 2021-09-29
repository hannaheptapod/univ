#include <iostream>
#include <vector>
using namespace std;

//行列のサイズを聞く
int askMatrixSize(string question) {
    
    int input = 0;
    cout << question << "の数を入力:";
    cin >> input;
    cout << endl;
    return input;
}

//行列(2次元配列)を作って返す
vector<vector<int>> makeMatrix(int mat_row, int mat_column) {
    
    cout << endl;
    vector<vector<int>> mat(mat_row, vector<int>(mat_column));
    
    for(int i = 0; i < mat_row; i++) {
        cout << i + 1 << "行目を入力:";
        for(int j = 0; j < mat_column; j++) {
            cin >> mat[i][j];
        }
        
        for(int j = 0; j < mat.at(i).size(); j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return mat;
}

//行列の積を計算してその結果を返す (行列を扱えるライブラリがある？)
vector<vector<int>> multiMatrix(vector<vector<int>> mat1, vector<vector<int>> mat2) {
    
    vector<vector<int>> mat(mat1.size(), vector<int>(mat2.at(0).size()));
    
    for(int i = 0; i < mat1.size(); i++) {
        for(int j = 0; j < mat1.at(i).size(); j++) {
            int sum = 0;
            
            for(int k = 0; k < mat1.at(i).size(); k++) {
                sum += mat1[i][k] * mat2[j][k];
            }
            mat[i][j] = sum;
        }
    }
    return mat;
}

//行列を表示する
int printMatrix(vector<vector<int>> mat) {
   
   cout << endl;
   for(int i = 0; i < mat.size(); i++) {
       for(int j = 0; j < mat.at(i).size(); j++) {
           cout << mat[i][j] << " ";
       }
       cout << endl;
   }
   return 0;
}

int main(int argc, const char * argv[]) {

    vector<vector<int>> mat1 = makeMatrix(askMatrixSize("行列1の行"), askMatrixSize("行列1の列"));
    cout << endl;
    vector<vector<int>> mat2 = makeMatrix(askMatrixSize("行列2の行"), askMatrixSize("行列2の列"));
    cout << endl;
    
    if(mat1[0].size() == mat2.size()) {
        printMatrix(multiMatrix(mat1, mat2));
    } else {
        cout << "-" << endl;
    }
    return 0;
}
