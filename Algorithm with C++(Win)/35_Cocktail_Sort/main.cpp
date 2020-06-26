#include <iostream>
#include <cstdlib>
#include <time.h>
#define SIZE 10

using namespace std;

void Bubble_Sort(int*);

void Swap(int &a, int &b);

int main() {

    int arr[] = {10, 9, 7, 8, 6, 5, 4, 3, 2, 1};
    
    cout << "Origion..." << endl;
    for (int i = 0; i < SIZE; i++) cout << arr[i] << " ";

    cout << endl << "After Cocktail Sort..." << endl;
    Bubble_Sort(arr);

    system("pause");
    return 0;
}

void Bubble_Sort(int *arr) {
    int start = 0, end = SIZE - 1, comparison_Times = 0;
    bool swap = true;
    time_t start_T, end_T;
    start_T = time(NULL);
    while (swap) {

        swap = false;
        
        for (int i = start; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                Swap(arr[i], arr[i + 1]);
                swap = true;
            }
            comparison_Times++;
        }

        // 當不需要交換時，即可停止，不須等到 start 和 end 相碰
        if (!swap) break;
        swap = false;

        end--;
        for (int j = end; j > start; j--) {
            if (arr[j] < arr[j - 1]){
                Swap(arr[j], arr[j - 1]);
                swap = true;
            }
            comparison_Times++;
        }
        start++;
    }
    end_T = time(NULL);

    cout << "time： " << difftime(start_T, end_T) << endl;
    for (int i = 0; i < SIZE; i++) cout << arr[i] << " ";
    cout << endl << "Comparison Times： " << comparison_Times << endl;
}

void Swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}