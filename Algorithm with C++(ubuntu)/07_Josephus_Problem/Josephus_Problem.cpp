#include <iostream>
#include <cstdlib>
#define LEN 41
#define STEP 3

using namespace std;

void Josephus (int*, int, int);

int Next (int*, int, int, int);

int Winner (int, int);

int main () {

    int man[LEN] = {0};
    Josephus (man, LEN, STEP);
    
    cout << "¬ù·æ¤Ò±Æ¦C¡G";
    for (int i = 0; i < LEN; i++) cout <<man[i] << " ";
    cout << endl << "Winner¡G" << Winner(LEN, STEP);
    
    system("pause");
    return 0;
}

void Josephus (int* man, int len, int k) {
    int i, n;
    for (i = 1, n = -1; i <= len; i++) {
        n = Next(man, len, k, n);
        man[n] = i;
    }
}

int Next (int *man, int len, int k, int n) {
    int count = 0;
    while (count < k) {
        n = (n + 1) % len;
        if (man[n] == 0) count++;
    }
    return n;
}

int Winner(int len, int k) {
    int g, n;
    for (g = 0, n = 1; n <= len; n++) g = (g + k) % n;
    return g + 1;
}