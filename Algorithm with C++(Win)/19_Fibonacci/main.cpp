#include <iostream>
#include <cstdlib>

using namespace std;

int GCD(int, int);

int main() {
    
   int num1 = 0, num2 = 0;
   cout << "�п�J��1�ӼơG ";
   cin >> num1;
   cout << "�п�J��2�ӼơG ";
   cin >> num2;
   cout << num1 << " �M " << num2 << "���̤j���]�Ƭ��G " << GCD(num1, num2) << endl;
    
    system("pause");
    return 0;
}

int GCD(int n1, int n2) {
    if (n1 % n2 == 0) return n2;
    else return GCD(n2, n1 % n2);
}