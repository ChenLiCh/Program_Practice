/* N * N 奇數幻方 
   規則
   把1放置在第一行的中間。
   順序將2,3,... 等數放在右上方格中。
   當右上方格出界的時候，則由另一邊進入。
   當右上方格中已經填有數，則把數填入正下方的方格中。
   按照以上步驟直到填寫完所有 N * N 個方格。
*/

#include <iostream>
#include <iomanip>
#include <memory.h>

using namespace std;

int main () {
    cout << "請輸入幻方的大小N(N是一個大於1的奇數):";
    int n = 1;
    cin >> n;
    cout << endl;

    // 初始化矩陣全為0
    int **matrix = new int *[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
        memset(matrix[i], 0, n*sizeof(int));
    }

    // 製作魔幻方陣
    int row = 0, col = n/2;
    for (int i = 1; i <= n*n; i++) {
        matrix[row][col] = i;
        row--;
        col++;

        if (row < 0 && col == n) {
            col--;
            row+=2;
        }
        else if (row < 0) {
            row = n - 1;
        }
        else if (col == n) {
            col = 0;
        }
        else if (matrix[row][col] != 0) {
            col--;
            row+=2;
        }
    }

    // 輸出
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(6) << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    // 釋放記憶體
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    system("pause");
    return 0;
}