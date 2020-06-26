#include <iostream>
#include <cstdlib>
#include <vector>
#define MAX 99999

using namespace std;

void Merge_Sort(vector<int>&, int, int);

void Merge(vector<int>&, int, int, int);

int main(){

    int arr[] = {5,3,8,6,2,7,1,4};
    vector<int> v1(arr, arr+sizeof(arr)/sizeof(int));

    cout << "Origion..." << endl;
    for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) cout << *it << " ";
    
    cout << endl << "Merge Sort..." << endl;
    Merge_Sort(v1, 0, v1.size() - 1);
    for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) cout << *it << " ";

    system("pause");
    return 0;
}

void Merge_Sort(vector<int>& v, int front, int end) {
    if (front < end) {
        int mid = (front + end) / 2;
        Merge_Sort(v, front, mid);
        Merge_Sort(v, mid + 1, end);
        Merge(v, front, mid, end);
    }
}

void Merge(vector<int>& v, int front, int mid, int end) {
    vector<int> left(v.begin() + front, v.begin() + mid + 1);
    vector<int> right(v.begin() + mid + 1, v.begin() + end + 1);

    left.insert(left.end(), MAX);
    right.insert(right.end(), MAX);

    int left_Index = 0, right_Index = 0;

    for (int i = front; i <= end; i++) {
        if (left[left_Index] <= right[right_Index]) {
            v[i] = left[left_Index];
            left_Index++;
        }
        else {
            v[i] = right[right_Index];
            right_Index++;
        }
    }
}