#include <iostream>
#include <cstdlib>
#define SIZE 10
using namespace std;

void Quick_Sort(int*, int, int);

int Partition(int*, int, int);

void Swap(int*, int*);

int main(){

    int arr[SIZE] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    cout << "Origion..." << endl;
    for (int i = 0; i < SIZE; i++) cout << arr[i] << " ";
    
    cout << endl << "Quick Sort..." << endl;
    Quick_Sort(arr, 0, SIZE - 1);
    for (int i = 0; i < SIZE; i++) cout << arr[i] << " ";

    system("pause");
    return 0;
}

void Quick_Sort(int* arr, int front, int end) {

    if (front < end) {
        int pivot = Partition(arr, front, end);
        Quick_Sort(arr, front, pivot - 1);
        Quick_Sort(arr, pivot + 1, end);
    }
}

int Partition(int *arr, int front, int end) {

    int i = 0, j = front - 1;
    for (i = front; i <= end - 1; i++) {
        if (arr[i] < arr[end]) {
            j++;
            Swap(&arr[j], &arr[i]);
        }
    }
    j++;
    Swap(&arr[j], &arr[end]);
    return j;
}

void Swap(int *a, int *b) {

    int temp = *a;
    *a = *b;
    *b = temp;
}