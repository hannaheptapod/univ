#include <iostream>
#include <vector>
using namespace std;

void input(int& n);
int step(int input);

int main() {
    int n = 0;
    input(n);
    cout << step(n);

}

void input (int& n) {
    cout << "数字を入力してください:";
    cin >> n;
}

int step(int input) {
    if (input == 1) return 1;
    return input * step(input - 1);
}