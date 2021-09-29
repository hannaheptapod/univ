#include <iostream>
#include <vector>
using namespace std;

struct student{
    string name;
    double height;
    double weight;
    int score;
};

void input(student& output, int i);
void output(student output);

int main() {
    int studentNum;
    cout << "生徒の人数を入力してください:";
    cin >> studentNum;
    vector<student> students(studentNum);
    for (int i = 0; i < studentNum; i++) {
        input(students[i], i);
    }
    for (int i = 0; i < studentNum; i++) {
        output(students[i]);
    }
    return 0;
}

void input(student& output, int i) {
    cout << i + 1 << "人目の名前を入力してください:";
    cin >> output.name;
    cout << i + 1 << "人目の身長を入力してください(m):";
    cin >> output.height;
    cout << i + 1 << "人目の体重を入力してください(kg):";
    cin >> output.weight;
    cout << i + 1 << "人目のテストの点数を入力してください:";
    cin >> output.score;
}

void output(student output) {
    cout << output.name << "の成績は" << output.score << "，BMIは" << (output.weight / (output.height * output.height)) << "です．" << endl;
}