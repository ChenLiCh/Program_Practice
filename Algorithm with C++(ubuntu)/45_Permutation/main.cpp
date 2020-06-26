#include <iostream>
#include <cstdlib>
#define SIZE 4

using namespace std;

void Permatation(char[], int, int);
void Swap(char[], int, int);

int main() {

    cout << "�п�J�n�ƦC���r���r��: " << endl;

    char arr[SIZE + 1] = "";
    cin >> arr;

    cout << "��X ";
    for(int i = 0; i < SIZE; i++)
        cout <<arr[i];
    cout << " ���Ҧ��ƦC�զX: " << endl;

    Permatation(arr, 0, SIZE - 1);

    system("pause");
    return 0;
}

void Permatation(char arr[], int i, int n) {

    if(i == n) {
        for (int j = 0; j < SIZE; j++)
            cout << arr[j];
        cout << endl;
    }
    else {
        for(int j = i; j <= n; j++) {
            Swap(arr, i, j);
            Permatation(arr, i + 1, n);
            Swap(arr, i, j);
        }
    }
}

void Swap(char arr[], int i, int j) {

    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}