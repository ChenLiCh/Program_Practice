#include <iostream>
#include <cstdlib>
using namespace std;

int Binary_Search(int[], int, int, int);

int main(void) {
    int arr[] = { 2, 3, 4, 10, 40};
	int find_Num = 10;
	int n = sizeof(arr) / sizeof(arr[0]);
	int result = Binary_Search(arr, 0, n - 1, find_Num);
	if (result == -1)
		cout << "Element is not present in array" << endl;
	else
		cout << "Element is present at index " << result << endl;

    system("pause");
	return 0;	
}

int Binary_Search(int arr[], int start, int end, int find_Num) {
	int mid = 0;
	
	while (start <= end) {
		mid = (start + end) / 2;
		
		if (arr[mid] == find_Num)
			return mid;		
		else if (arr[mid] < find_Num)
			start = mid + 1;
		else if (arr[mid] > find_Num)
			end = mid - 1;
	}

	return -1;
}