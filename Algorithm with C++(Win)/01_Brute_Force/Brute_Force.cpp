#include <iostream>
#include <cstdlib>
#include <string>
#define SIZE 100

using namespace std;

void Compare(const char *compare_str1, const char *compare_str2, int, int);

int main() {
    char *str1 = NULL, *str2 = NULL;
    str1 = new char[SIZE];
    str2 = new char[SIZE];

    cout << "�п�J��1�Ӧr��: ";
    cin >> str1;
    cout << "�п�J��2�Ӧr��: ";
    cin >> str2;
    
    // �p��r�����
    int str1_length = 0, str2_length = 0;
    for (int i = 0; i < SIZE && str1[i] != '\0'; i++) {
        str1_length++;
    }
    for (int i = 0; i < SIZE && str2[i] != '\0'; i++) {
        str2_length++;
    }
    
    if (str1_length >= str2_length)Compare(str1, str2, str1_length, str2_length);
    else Compare(str2, str1, str2_length, str1_length);

    system("pause");
    return 0;
}

void Compare(const char *compare_str1, const char *compare_str2, int length1, int length2) {

    int move_index = 0, correct_times = 0;
    
    for (int i = 0; i < length1; i++) {
        move_index = i;
        correct_times = 0;
        for (int j = 0; j < length2; j++) {
            if (compare_str1[move_index] == compare_str2[j]) {
                move_index++;
                correct_times++;
                if (correct_times == sizeof(compare_str2) - 1) {
                    cout << compare_str2 << " �O " << compare_str1 << " ���l�r��" << endl;
                    return;
                }
            }
            else break;
        }
    }
    cout << compare_str2 << " ���O " << compare_str1 << " ���l�r��" << endl;
    return;
}