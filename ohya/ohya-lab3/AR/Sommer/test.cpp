#include <bits/stdc++.h>
unsigned long long pb, ob, nb, lb = 0x0ULL;
const unsigned long long horW = 0x7e7e7e7e7e7e7e7eULL;
const unsigned long long verW = 0x00ffffffffffff00ULL;
const unsigned long long allW = 0x007e7e7e7e7e7e00ULL;
int b[64] = {
    2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,
    2,2,2,1,1,1,2,2,
    2,2,0,0,1,2,2,2,
    2,2,2,1,0,2,2,2,
    2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2
};
void print() {
    for (int i = 63; i >= 0; i--) {
        char s = ' ';
        if (1ULL<<i & pb) s = 'o';
        else if (1ULL<<i & ob) s = 'x';
        std::cout << s;
        if (i%8 == 0) std::cout << std::endl;
    }
}
void print(unsigned long long board) {
    for (int i = 63; i >= 0; i--) {
        unsigned char s = ' ';
        if (1ULL<<i & board) s = 'o';
        std::cout << s;
        if (i%8 == 0) std::cout << std::endl;
    }
}
void check() {
    unsigned long long tmp;
    unsigned long long hor = ob & horW;
    unsigned long long ver = ob & verW;
    unsigned long long all = ob & allW;

    tmp = hor & (pb << 1);
    for (int i = 0; i < 5; i++) tmp |= hor & (tmp << 1);
    lb  = nb & (tmp << 1);
    tmp = hor & (pb >> 1);
    for (int i = 0; i < 5; i++) tmp |= hor & (tmp >> 1);
    lb |= nb & (tmp >> 1);
    tmp = ver & (pb << 8);
    for (int i = 0; i < 5; i++) tmp |= ver & (tmp << 8);
    lb |= nb & (tmp << 8);
    tmp = ver & (pb >> 8);
    for (int i = 0; i < 5; i++) tmp |= ver & (tmp >> 8);
    lb |= nb & (tmp >> 8);
    tmp = all & (pb << 7);
    for (int i = 0; i < 5; i++) tmp |= all & (tmp << 7);
    lb |= nb & (tmp << 7);
    tmp = all & (pb >> 7);
    for (int i = 0; i < 5; i++) tmp |= all & (tmp >> 7);
    lb |= nb & (tmp >> 7);
    tmp = all & (pb << 9);
    for (int i = 0; i < 5; i++) tmp |= all & (tmp << 9);
    lb |= nb & (tmp << 9);
    tmp = all & (pb >> 9);
    for (int i = 0; i < 5; i++) tmp |= all & (tmp >> 9);
    lb |= nb & (tmp >> 9);
    print(lb);
}
int main() {
    for (int i = 0; i < 64; i++) {
        pb <<= 1ULL;
        ob <<= 1ULL;
        if (b[i] == 0) pb += 1ULL;
        else if (b[i] == 1) ob += 1ULL;
    }
    nb = ~(pb | ob);
    print();
    std::cout << std::endl;
    std::cout << std::endl;
    check();
}