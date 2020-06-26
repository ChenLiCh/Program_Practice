#include <iostream>
#include <cstdlib>

using namespace std;

int Fib(int);

int main(void) {
	int number = 0;
	cin >> number;
	cout << Fib(number) << endl;

    system("pause");
	return 0;
}

int Fib(int n) {
	if (n <= 1)
		return n;
	return Fib(n-1) + Fib(n-2);
}