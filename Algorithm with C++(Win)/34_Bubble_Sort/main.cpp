#include <iostream>
#include <cstdlib>
#define SIZE 10

using namespace std;

void Bubble_Sort(int*);

void Swap(int &a, int &b);

int main() {

    int arr[] = {10, 9, 7, 8, 6, 5, 4, 3, 2, 1};
    
    cout << "Origion..." << endl;
    for (int i = 0; i < SIZE; i++) cout << arr[i] << " ";

    cout << endl << "After Bubble Sort..." << endl;
    Bubble_Sort(arr);

    system("pause");
    return 0;
}

void Bubble_Sort(int *arr) {
    int end = SIZE - 1, comparison_Times = 0;
    for (; end > 0; end--) {
        for (int i = 0; i < end; i++) {
            if (arr[i] > arr[i + 1])
                Swap(arr[i], arr[i + 1]);
            comparison_Times++;
        }
    }
    for (int i = 0; i < SIZE; i++) cout << arr[i] << " ";
    cout << endl << "Comparison Times¡G " << comparison_Times << endl;
}

void Swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}