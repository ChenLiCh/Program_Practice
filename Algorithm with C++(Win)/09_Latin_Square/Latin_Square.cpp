#include <iostream>
#include <cstdlib>
#define SIZE 4

using namespace std;

int main () {

    cout << "拉丁方陣大小為 " << SIZE << " * " << SIZE << endl;

    int square[SIZE][SIZE] = {0}, begin_Number = 1;
    for (int i = 0; i < SIZE; i++) {
        begin_Number = i + 1;
        for (int j = 0; j < SIZE; j++) {
            square[i][j] = begin_Number;
            begin_Number++;
            if (begin_Number > SIZE) begin_Number = 1;
        }
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << square[i][j] << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}