#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

void Prefix_Table (char[], int[], int);
void Move_Prefix_Table (int[], int);
void KMP_Search (char[], char[]);

int main () {
    
    char text[] = "ABABABCABAABABABAB";
    char pattern[] = "ABABCABAA";

    KMP_Search(text, pattern);
    
    system("pause");
    return 0;
}

// 找出最長的前綴
void Prefix_Table (char pattern[], int prefix[], int n) {
    prefix[0] = 0;
    int len = 0, i = 1;

    while (i < n) {
        if (pattern[i] == pattern[len]) {
            len++;
            prefix[i] = len;
            i++;
        }
        else {
            if (len > 0) {
                len = prefix[len - 1];
            }
            else {
                prefix[i] = 0;
                i++;
            }
        }
    }
}

void Move_Prefix_Table (int prefix[], int n) {
    int i = 0;
    for (i = n - 1; i > 0; i--) {
        prefix[i] = prefix[i - 1];
    }
    prefix[0] = -1;
}

void KMP_Search (char text[], char pattern[]) {
    
    int m = strlen(text), n = strlen(pattern);
    int *prefix = new int(sizeof(int) * n);

    Prefix_Table(pattern, prefix, n);
    Move_Prefix_Table (prefix, n);

    // text[i],    len(text)    = m
    // pattern[j], len(pattern) = n
    int i = 0, j = 0;

    while (i < m) {
        if (j == n - 1 && text[i] == pattern[j]) {
            cout << "Found pattern at " << i - j << endl;
            j = prefix[j];
        }
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }
        else {
            j = prefix[j];
            if (j == -1) {
                i++;
                j++;
            }
        }
    }
}