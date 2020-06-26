#include <cstdlib>
#include <iostream>
using namespace std;

template <class T>
void Selection_Sort (T []);

int main() {
	
	int arr[5] = {};
	float arr_f[5] = {};
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}
	Selection_Sort<int>(arr);
	//Selection_Sort<float>(arr_f);
	
	system("pause");
	return 0;
}

template <class T>
void Selection_Sort(T arr[]) {
	cout << "由大到小排序： ";
	int max_index = 0;
	T temp = 0;
	for (int i = 0; i < 4; i++) {
		max_index = i;
		for (int j = i + 1; j < 5; j++) 
			if (arr[max_index] < arr[j]) max_index = j;
		temp = arr[i];
		arr[i] = arr[max_index];
		arr[max_index] = temp;
	}

	for (int i = 0; i < 5; i++) cout << arr[i] << " ";
	cout << endl << "====================" << endl;
}