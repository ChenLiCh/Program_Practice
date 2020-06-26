#include <iostream>
#include <cstdlib>
#define SIZE 10
using namespace std;

void Insertion_Sort(int*);

int Binary_Search(int*, int, int, int);

int main() {

    int arr[SIZE] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    cout << "Origion..." << endl;
    for (int i = 0; i < SIZE; i++) cout << arr[i] << " ";

    cout << endl << "Insertion Sort(increase)..." << endl;
    Insertion_Sort(arr);

    system("pause");
    return 0;
}

void Insertion_Sort(int *arr) {

    int comparison_Times_Total = 0;
    for (int i = 1; i < SIZE; i++) 
        comparison_Times_Total += Binary_Search(arr, 0, i - 1, arr[i]);

    cout << endl << "Total Comparison Times¡G " << comparison_Times_Total << endl;
    for (int i = 0; i < SIZE; i++) cout << arr[i] << " ";
}

int Binary_Search(int *arr, int start, int end, int target) {
	int mid = 0, comparison_Times = 0;
	int end2 = end;
	while (start <= end) {
		mid = (start + end) / 2;
		comparison_Times++;
		if (arr[mid] == target)
	        break;		
		else if (arr[mid] < target)
			start = mid + 1;
		else if (arr[mid] > target)
			end = mid - 1;
	}

    if (arr[mid] <= target) {
        while(end2 > mid) {
            arr[end2 + 1] = arr[end2];
            end2--;
        }
        arr[end2 + 1] = target;
    }
	else if (arr[mid] > target) {
        while(end2 >= mid) {
            arr[end2 + 1] = arr[end2];
            end2--;
        }
        arr[end2 + 1] = target;
    }

    cout << comparison_Times << " ";
    return comparison_Times;
}