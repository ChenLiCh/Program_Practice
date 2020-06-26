/* N * N �_�Ƥۤ� 
   �W�h
   ��1��m�b�Ĥ@�檺�����C
   ���ǱN2,3,... ���Ʃ�b�k�W��椤�C
   ��k�W���X�ɪ��ɭԡA�h�ѥt�@��i�J�C
   ��k�W��椤�w�g�񦳼ơA�h��ƶ�J���U�誺��椤�C
   ���ӥH�W�B�J�����g���Ҧ� N * N �Ӥ��C
*/

#include <iostream>
#include <iomanip>
#include <memory.h>

using namespace std;

int main () {
    cout << "�п�J�ۤ誺�j�pN(N�O�@�Ӥj��1���_��):";
    int n = 1;
    cin >> n;
    cout << endl;

    // ��l�Ưx�}����0
    int **matrix = new int *[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
        memset(matrix[i], 0, n*sizeof(int));
    }

    // �s�@�]�ۤ�}
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

    // ��X
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(6) << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    // ����O����
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    system("pause");
    return 0;
}