#include <iostream>
#include <iomanip>

using namespace std;
#define SIZE 8

int main () {
    int matrix[SIZE][SIZE] = {0}, z_matrix[SIZE][SIZE] = {0};
    int i = 0, j = 0, value = 0;

    // 初始化原本陣列
    for(i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            matrix[i][j] = value;
            value++;
        }
    }
    
    //Z字型編排
    i = j = 0;
    for (int matrix_i = 0; matrix_i < SIZE; matrix_i++) {
        for (int matrix_j = 0; matrix_j < SIZE; matrix_j++) {
            z_matrix[i][j] = matrix[matrix_i][matrix_j];
            if (j%2 == 0 && (i == 0 || i == 7)) {
                j++;
            }
            else if (i%2 == 1 && (j == 0 || j == 7)) {
                i++;
            }
            else if ((i+j)%2 == 0) {
                j++;
                i--;
            }
            else if ((i+j)%2 == 1) {
                i++;
                j--;
            }
        }
    }

    //印出Z字型編排
    for(i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            cout << setw(4) << z_matrix[i][j];
        }
        cout << endl;
    }
    system("pause");
    return 0;
}