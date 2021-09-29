#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct unit {
    int x, y, value;
};

class gamemanager {
    const int WIDTH = 20;
    const int HEIGHT = 15;
    const int TARGET = 3000;
    string inputKey;
    unit player;
    unit enemy;
    vector<unit> money;

public:
    void gameMain();
    void gameInit();

    void printMap();
    void keyInput();

    void playerMove();
    void enemyMove();
    bool flagEnemy;
    void popMoney();
    int checkMoney(int inputx, int inputy);
    void checkGetMoney();
    void printHoldMoney();

    bool isCaptured;
    void checkCaptured();
    bool isClear;
    void checkClear();
};

void gamemanager::gameMain() {
    gameInit();
    while (!isClear && !isCaptured) {
        //system("cls");//Win
        system("clear");//Mac
        unsigned int nowtime = (unsigned int)time(NULL);
        srand(nowtime);
        printMap();
        printHoldMoney();
        keyInput();
        playerMove();
        enemyMove();
        checkGetMoney();
        checkCaptured();
        checkClear();
        if (player.value > 1000 && flagEnemy == false) {
            do {
                enemy.x = (rand() % WIDTH) + 1;
                enemy.y = (rand() % HEIGHT) + 1;
            } while (enemy.x == player.x && enemy.y == player.y);
            flagEnemy = true;
        }
    }
}
void gamemanager::gameInit() {
    isClear = false;
    flagEnemy = false;
    isCaptured = false;
    unsigned int nowtime = (unsigned int)time(NULL);
    srand(nowtime);
    player.x = (rand() % WIDTH) + 1;
    player.y = (rand() % HEIGHT) + 1;
    player.value = 0;
    for (int i = 0; i < 3; i++) popMoney();
}

void gamemanager::printMap() {
    for(int drawy = HEIGHT; drawy >= 1; drawy--) {
        for (int drawx = 1; drawx <= WIDTH; drawx++) {
            if (player.x == drawx && player.y == drawy) cout << 'P';
            else if (enemy.x == drawx && enemy.y == drawy) cout << 'E';
            else if (checkMoney(drawx, drawy) != -1) cout << 'M';
            else cout << '.';
        } 
    cout << endl;
    }
}
void gamemanager::keyInput() {
    cout << "キー入力待機:";
    cin >> inputKey;
}

void gamemanager::playerMove() {
    if (inputKey == "w") {
        if (player.y == HEIGHT) player.y = 1; else player.y++;
    } else if (inputKey == "s") {
        if (player.y == 1) player.y = HEIGHT; else player.y--;
    } else if (inputKey == "a") {
        if (player.x == 1) player.x = WIDTH; else player.x--;
    } else if (inputKey == "d") {
        if (player.x == WIDTH) player.x = 1; else player.x++;
    }
}
void gamemanager::enemyMove() {
    if (enemy.x == player.x && enemy.y == player.y) isCaptured = true;
    if (inputKey == "w" || inputKey == "s" || inputKey == "a" || inputKey == "d") {
        if (abs(enemy.x - player.x) > abs(enemy.y - player.y)) {
            if (enemy.x < player.x) enemy.x++;
            else enemy.x--;
        } else if (abs(enemy.x - player.x) < abs(enemy.y - player.y)) {
            if (enemy.y < player.y) enemy.y++;
            else enemy.y--;
        } else {
            int i = rand() % 2;
            if (i == 0) {
                if (enemy.x < player.x) enemy.x++;
            else enemy.x--; 
            } else {
                if (enemy.y < player.y) enemy.y++;
            else enemy.y--;
            }
        } 
    }
    if (enemy.x == player.x && enemy.y == player.y) isCaptured = true;
}

void gamemanager::popMoney() {
    unit popedmoney;
    popedmoney.x = (rand() % WIDTH) + 1;
    popedmoney.y = (rand() % HEIGHT) + 1;
    popedmoney.value = rand() % 1000;
    money.push_back(popedmoney);
}
int gamemanager::checkMoney(int inputx, int inputy) {
    for (int i = 0; i < money.size(); i++) {
        if (money[i].x == inputx && money[i].y == inputy) return i;
    }
    return -1;
} 
void gamemanager::checkGetMoney() {
    int checkgetmoney = checkMoney(player.x, player.y);
    if (checkgetmoney != -1) {
        player.value += money[checkgetmoney].value;
        money.erase(money.begin() + checkgetmoney);
        popMoney();
    }
}
void gamemanager::printHoldMoney() {
    cout << "現在の所持金:" << player.value << endl;
}

void gamemanager::checkCaptured() {
    if (isCaptured == true) cout << "ゲームオーバー！" << endl << "敵に捕まりました．" << endl;
}
void gamemanager::checkClear() {
    if (player.value > TARGET) {
        cout << "ゲームクリア！" << endl << player.value << "円獲得しました．" << endl;
        isClear = true;
    }
}

int main() {
    gamemanager game;
    game.gameMain();
    return 0;
}