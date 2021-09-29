#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct linechecker {
    vector<int> line = vector<int>(2);
};

class gameComponent {
    linechecker fA, fB, fC;
    linechecker r3, r2, r1;
    linechecker dA, dC;
    string key;

public:
    void gameMain();
    void gameInit();
    int turn = 0;
    int prec = 0;

    vector<vector<int>> boardStatus = vector<vector<int>>(3, vector<int>(3));
    void printBoard();
    void cellOutput(int cellStatus);

    void keyInput();
    void playerAct();

    int cpuLv;
    vector<int> eval();
    void cpuAct();

    void checkClear();
    int gameset;
    void printResult();
};

void gameComponent::gameMain() {
    if (prec == 0) {
        while (gameset == 0) {
            printBoard();
            playerAct();
            checkClear();
            if (gameset == 0) { cpuAct(); printBoard(); checkClear(); }
            if (gameset != 0) printResult();
            else system("clear");
        }
    } else {
        while (gameset == 0) {
            cpuAct();
            checkClear();
            printBoard();
            if (gameset == 0) { playerAct(); checkClear(); }
            if (gameset != 0) printResult();
            else system("clear");
        }
    }
}
void gameComponent::gameInit() {
    gameset = 0;
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) boardStatus[row][column] = 0;
        }
    fA.line = fB.line = fC.line = r3.line = r2.line = r1.line = dA.line = dC.line = {0, 0};
    cout << "CPUの強さを選んでください．(弱い: 0, 強い: 1) :";
    cin >> cpuLv;
    cout << "先攻/後攻を選んでください．(先攻: 0, 後攻: 1) :";
    cin >> prec;
    srand((unsigned) time(NULL));
    system("clear");
}
void gameComponent::keyInput() {
    cout << "キー入力待機:";
    cin >> key;
}
void gameComponent::cellOutput(int cellStatus) {
    switch (cellStatus) {
        case 0:
            cout << "- ";
            break;
        case 1:
            cout << "o ";
            break;
        case -1:
            cout << "x ";
            break;
        default:
            break;
    }
}
void gameComponent::printBoard() {
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) cellOutput(boardStatus[row][column]);
        cout << endl;
    }
    cout << endl;
}
void gameComponent::checkClear() { 
    if (turn == 9) {
        gameset = 2;
    } else if (fA.line[0] == 3 || fB.line[0] == 3 || fC.line[0] == 3 || r3.line[0] == 3 || r2.line[0] == 3 || r1.line[0] == 3 || dA.line[0] == 3 || dC.line[0] == 3) {
        gameset = 1;
    } else if (fA.line[1] == 3 || fB.line[1] == 3 || fC.line[1] == 3 || r3.line[1] == 3 || r2.line[1] == 3 || r1.line[1] == 3 || dA.line[1] == 3 || dC.line[1] == 3) {
        gameset = -1;
    }
}
void gameComponent::printResult() {
        system("clear");
        printBoard();
    if (gameset == 1) {
        cout << "勝利しました！" << endl << "ゲームを終了します．";
    } else if (gameset == -1) {
        cout << "敗北しました……" << endl << "ゲームを終了します．";
    } else if (gameset == 2) {
        cout << "引き分けました．" << endl << "ゲームを終了します．";
    }
}
void gameComponent::playerAct() {
    cout << "a3 b3 c3" << endl << "a2 b2 c2" << endl << "a1 b1 c1" << endl << endl << "マスを選んでください．" << endl << endl;
    keyInput();
    if (key == "a3" && boardStatus[0][0] == 0) {
        boardStatus[0][0] = 1;
        fA.line[0]++;
        r3.line[0]++;
        dA.line[0]++;
        turn++;
    } else if (key == "a2" && boardStatus[1][0] == 0) {
        boardStatus[1][0] = 1;
        fA.line[0]++;
        r2.line[0]++;
        turn++;
    } else if (key == "a1" && boardStatus[2][0] == 0) {
        boardStatus[2][0] = 1;
        fA.line[0]++;
        r1.line[0]++;
        dC.line[0]++;
        turn++;
    } else if (key == "b3" && boardStatus[0][1] == 0) {
        boardStatus[0][1] = 1;
        fB.line[0]++;
        r3.line[0]++;
        turn++;
    } else if (key == "b2" && boardStatus[1][1] == 0) {
        boardStatus[1][1] = 1;
        fB.line[0]++;
        r2.line[0]++;
        dA.line[0]++;
        dC.line[0]++;
        turn++;
    } else if (key == "b1" && boardStatus[2][1] == 0) {
        boardStatus[2][1] = 1;
        fB.line[0]++;
        r1.line[0]++;
        turn++;
    } else if (key == "c3" && boardStatus[0][2] == 0) {
        boardStatus[0][2] = 1;
        fC.line[0]++;
        r3.line[0]++;
        dC.line[0]++;
        turn++;
    } else if (key == "c2" && boardStatus[1][2] == 0) {
        boardStatus[1][2] = 1;
        fC.line[0]++;
        r2.line[0]++;
        turn++;
    } else if (key == "c1" && boardStatus[2][2] == 0) {
        boardStatus[2][2] = 1;
        fC.line[0]++;
        r1.line[0]++;
        dA.line[0]++;
        turn++;
    }
}
vector<int> gameComponent::eval() {//CPUの最適手，かなり無駄が多い書き方になっていそう
    int evalFa = fA.line[1] - fA.line[0];
    int evalFb = fB.line[1] - fB.line[0];
    int evalFc = fC.line[1] - fC.line[0];
    int evalR3 = r3.line[1] - r3.line[0];
    int evalR2 = r2.line[1] - r2.line[0];
    int evalR1 = r1.line[1] - r1.line[0];
    int evalDa = dA.line[1] - dA.line[0];
    int evalDc = dC.line[1] - dC.line[0];

    vector<int> result(2);

//プレイヤーがCPUによるチェックを回避しなければCPUの勝ち
    if (evalFa == 2) {
        for (int row = 0; row < 3; row++) {
            if (boardStatus[row][0] == 0) result = {row, 0};
        }
    } else if (evalFb == 2) {
        for (int row = 0; row < 3; row++) {
            if (boardStatus[row][1] == 0) result = {row, 1};
        }
    } else if (evalFc == 2) {
        for (int row = 0; row < 3; row++) {
            if (boardStatus[row][2] == 0) result = {row, 2};
        }
    } else if (evalR3 == 2) {
        for (int column = 0; column < 3; column++) {
            if (boardStatus[0][column] == 0) result = {0, column};
        }
    } else if (evalR2 == 2) {
        for (int column = 0; column < 3; column++) {
            if (boardStatus[1][column] == 0) result = {1, column};
        }
    } else if (evalR1 == 2) {
        for (int column = 0; column < 3; column++) {
            if (boardStatus[2][column] == 0) result = {2, column};
        }
    } else if (evalDa == 2) {
        for (int row = 0; row < 3; row++) {
            if (boardStatus[row][row] == 0) result = {row, row};
        }
    } else if (evalDc == 2) {
        for (int row = 0; row < 3; row++) {
            if (boardStatus[row][2 - row] == 0) result = {row, 2 - row};
        }
    }
//CPUがチェックメイトできる手がなければ，優先してプレイヤーのチェックを回避する
    else if (-evalFa == 2) {
        for (int row = 0; row < 3; row++) {
            if (boardStatus[row][0] == 0) result = {row, 0};
        }
    } else if (-evalFb == 2) {
        for (int row = 0; row < 3; row++) {
            if (boardStatus[row][1] == 0) result = {row, 1};
        }
    } else if (-evalFc == 2) {
        for (int row = 0; row < 3; row++) {
            if (boardStatus[row][2] == 0) result = {row, 2};
        }
    } else if (-evalR3 == 2) {
        for (int column = 0; column < 3; column++) {
            if (boardStatus[0][column] == 0) result = {0, column};
        }
    } else if (-evalR2 == 2) {
        for (int column = 0; column < 3; column++) {
            if (boardStatus[1][column] == 0) result = {1, column};
        }
    } else if (-evalR1 == 2) {
        for (int column = 0; column < 3; column++) {
            if (boardStatus[2][column] == 0) result = {2, column};
        }
    } else if (-evalDa == 2) {
        for (int row = 0; row < 3; row++) {
            if (boardStatus[row][row] == 0) result = {row, row};
        }
    } else if (-evalDc == 2) {
        for (int row = 0; row < 3; row++) {
            if (boardStatus[row][2 - row] == 0) result = {row, 2 - row};
        }
    }
//お互いにチェックがない場合
    else {
        int n = 0;
        int nA3 = (1 - abs(boardStatus[0][0])) * (abs(evalFa) + abs(evalR3) + abs(evalDa));
        if (n < nA3) {
            n = nA3;
            result = {0, 0};
            }
        int nA2 = (1 - abs(boardStatus[1][0])) * (abs(evalFa) + abs(evalR2));
        if (n < nA2) {
            n = nA2;
            result = {1, 0};
            }
        int nA1 = (1 - abs(boardStatus[2][0])) * (abs(evalFa) + abs(evalR1) + abs(evalDc));
        if (n < nA1) {
            n = nA1;
            result = {2, 0};
            }
        int nB3 = (1 - abs(boardStatus[0][1])) * (abs(evalFb) + abs(evalR3));
        if (n < nB3) {
            n = nB3;
            result = {0, 1};
            }
        int nB2 = (1 - abs(boardStatus[1][1])) * (abs(evalFb) + abs(evalR2) + abs(evalDa) + abs(evalDc));
        if (n < nB2) {
            n = nB2;
            result = {1, 1};
            }
        int nB1 = (1 - abs(boardStatus[2][1])) * (abs(evalFb) + abs(evalR1));
        if (n < nB1) {
            n = nB1;
            result = {2, 1};
            }
        int nC3 = (1 - abs(boardStatus[0][2])) * (abs(evalFc) + abs(evalR3) + abs(evalDc));
        if (n < nC3) {
            n = nC3;
            result = {0, 2};
            }
        int nC2 = (1 - abs(boardStatus[1][2])) * (abs(evalFc) + abs(evalR2));
        if (n < nC2) {
            n = nC2;
            result = {1, 2};
            }
        int nC1 = (1 - abs(boardStatus[2][2])) * (abs(evalFc) + abs(evalR1) + abs(evalDa));
        if (n < nC1) {
            n = nC1;
            result = {2, 2};
        }
        if (n == 0) {
            if (boardStatus[1][1] == 0) result = {1, 1};
            else while (boardStatus[result[0]][result[1]] != 0) {
                result[0] = rand() % 3;
                result[1] = rand() % 3;
            }
        }
    }
     return result;   
}
void gameComponent::cpuAct() {
    if ((turn + prec) % 2 == 1) {
        vector<int> cpu(2);
        if (cpuLv == 1) {
            cpu = eval();
        } else {
            do {
                cpu[0] = rand() % 3;
                cpu[1] = rand() % 3;
            } while (boardStatus[cpu[0]][cpu[1]] != 0);
        }
        switch (cpu[0]) {
            case 0:
                r3.line[1]++;
                break;
            case 1:
                r2.line[1]++;
                break;
            case 2:
                r1.line[1]++;
                break;
        }
        switch (cpu[1]) {
            case 0:
                fA.line[1]++;
                break;
            case 1:
                fB.line[1]++;
                break;
            case 2:
                fC.line[1]++;
                break;
        }
        if (cpu[0] - cpu[1] == 0) dA.line[1]++;
        if (cpu[0] + cpu[1] == 2) dC.line[1]++;
        boardStatus[cpu[0]][cpu[1]] = -1;
        turn++;
    }
}

int main() {
    gameComponent game;
    game.gameInit();
    game.gameMain();
    return 0;
}