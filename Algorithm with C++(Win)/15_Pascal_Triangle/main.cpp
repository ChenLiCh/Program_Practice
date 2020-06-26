#include <iostream>
#include <cstdlib>

using namespace std;

void Print_Pascal_Triangle(int);
int Factorial(int);

int main() {

    cout << "½Ð¿é¤J¶¥¼Æ¡G ";
    int n = 0;
    cin >> n;
    Print_Pascal_Triangle(n);
    system("pause");
    return 0;
}

void Print_Pascal_Triangle(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) 
            cout << Factorial(i) / (Factorial(j) * Factorial(i-j)) << " ";
        cout << endl;
    }     
}

int Factorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * Factorial(n-1);
}

// int Factorial(int n) {
//     int sum = 1;
//     for (int i = 1; i <= n; i++) sum *= i;
//     return sum;
// }