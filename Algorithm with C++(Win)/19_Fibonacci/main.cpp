#include <iostream>
#include <cstdlib>

using namespace std;

int GCD(int, int);

int main() {
    
   int num1 = 0, num2 = 0;
   cout << "請輸入第1個數： ";
   cin >> num1;
   cout << "請輸入第2個數： ";
   cin >> num2;
   cout << num1 << " 和 " << num2 << "的最大公因數為： " << GCD(num1, num2) << endl;
    
    system("pause");
    return 0;
}

int GCD(int n1, int n2) {
    if (n1 % n2 == 0) return n2;
    else return GCD(n2, n1 % n2);
}