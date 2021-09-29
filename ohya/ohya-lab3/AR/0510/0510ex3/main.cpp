#include <iostream>
#include <vector>
using namespace std;

class car {
    private:
        string name;
    public:
        void setName(string input);
        string getName();
        car();
        ~car();
};
void car::setName (string input) {
    name = input;
}
string car::getName() {
    return name;
}
car::car() {
    
}

int main() {

    return 0;
}