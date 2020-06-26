#include <iostream>
#include <cstdlib>
#define SIZE 10
using namespace std;

void Insertion_Sort(int*);

int main() {

    int arr[SIZE] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    cout << "原本..." << endl;
    for (int i = 0; i < SIZE; i++) cout << arr[i] << " ";

    cout << endl << "Insertion Sort排序後..." << endl;
    Insertion_Sort(arr);

    system("pause");
    return 0;
}

void Insertion_Sort(int *arr) {

    int j = 0, now = 0, comparison_Times = 0;
    for (int i = 1; i < SIZE; i++) {
        now = arr[i];
        j = i - 1;
        while(j >= 0 && now < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
            comparison_Times++;
        }
        arr[j + 1] = now;
    }

    for (int i = 0; i < SIZE; i++) cout << arr[i] << " ";

    cout << endl << "比較次數: " << comparison_Times << endl;
}