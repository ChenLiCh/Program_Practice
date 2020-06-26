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

    // 建立 table1 (存放原陣列中每個 element 出現的次數)
    for (int i = 0; i < SIZE; i++) {
        table1[arr[i]] += 1;
    }
    
    // 建立 table2(存放 table1 中出現的累積次數)
    table2[0] = table1[0];
    int temp = table2[0];
    for (int i = 1; i < MAX; i++) {
        table2[i] = temp + table1[i];
        temp = table2[i];
    }

    int output[SIZE] = {0};
    for (int i = SIZE - 1; i >= 0; i--) {
        output[table2[arr[i]] - 1] = arr[i]; // table2 取出的值要減1，因為要放在 output 從 0 數來第 n 個，其 index 值為 n - 1
        table2[arr[i]]--;
    }
    for (int i = 0; i < SIZE; i++) cout << output[i] << " ";
}