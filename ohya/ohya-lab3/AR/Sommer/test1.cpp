#include <bits/stdc++.h>
using namespace std;
int popcount(unsigned long long x) {
    x = x - ((x >> 1) & 0x5555555555555555ULL);
    x = (x & 0x3333333333333333ULL) + ((x >> 2) & 0x3333333333333333ULL);

    x = (x + (x >> 4)) & 0x0f0f0f0f0f0f0f0fULL;
    x = x + (x >> 8);
    x = x + (x >> 16);
    x = x + (x >> 32);
    x &= 0x7fULL;
    return (int)x;
}
int main() {
    unsigned long long i = 0x007e7e7e7e7e7e00ULL;
    cout << popcount(i) << endl;
    return 0;
}