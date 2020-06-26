#include <iostream>
#include <cstdlib>
#define SIZE 10
#define MAX 50

using namespace std;

void Counting_Sort(int*);

int main() {

    int arr[SIZE] = {4, 5, 3, 3, 1, 4, 7, 8, 9, 9};

    cout << "Origion..." << endl;
    for (int i = 0; i < SIZE; i++) cout << arr[i] << " ";

    cout << endl << "After Shell Sort..." << endl;
    Counting_Sort(arr);

    system("pause");
    return 0;
}

void Counting_Sort(int *arr) {
    int table1[MAX] = {0}, table2[MAX] = {0};

    // �إ� table1 (�s���}�C���C�� element �X�{������)
    for (int i = 0; i < SIZE; i++) {
        table1[arr[i]] += 1;
    }
    
    // �إ� table2(�s�� table1 ���X�{���ֿn����)
    table2[0] = table1[0];
    int temp = table2[0];
    for (int i = 1; i < MAX; i++) {
        table2[i] = temp + table1[i];
        temp = table2[i];
    }

    int output[SIZE] = {0};
    for (int i = SIZE - 1; i >= 0; i--) {
        output[table2[arr[i]] - 1] = arr[i]; // table2 ���X���ȭn��1�A�]���n��b output �q 0 �ƨӲ� n �ӡA�� index �Ȭ� n - 1
        table2[arr[i]]--;
    }
    for (int i = 0; i < SIZE; i++) cout << output[i] << " ";
}