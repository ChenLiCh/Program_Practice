#include <iostream>
#include <cstdlib>
#include <time.h>
#define SIZE 11

using namespace std;

void Shell_Sort(int*);

int main() {

    int arr[] = {10, 9, 7, 8, 6, 5, 4, 3, 2, 1, 0};
    
    cout << "Origion..." << endl;
    for (int i = 0; i < SIZE; i++) cout << arr[i] << " ";

    cout << endl << "After Shell Sort..." << endl;
    Shell_Sort(arr);
    for (int i = 0; i < SIZE; i++) cout << arr[i] << " ";

    system("pause");
    return 0;
}

void Shell_Sort(int *arr) {

    for (int gap = SIZE / 2; gap >= 1; gap /= 2) {
        for (int i = gap; i < SIZE; i++) {
            int temp = arr[i];
            int j = 0;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}