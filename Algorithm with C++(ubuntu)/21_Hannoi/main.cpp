#include <iostream>
#include <cstdio>
using namespace std;

void Hannoi(int, char, char, char);

int main() {
	int n;
	cin >> n;
	Hannoi(n, 'A', 'B', 'C');

	system("pause");
	return 0;
}

void Hannoi(int n, char from, char buffer, char to) {
	if (n == 0) return;
	Hannoi(n-1, from, to, buffer);
	cout << "Move disk " << n << " from " << from << " to " << to << endl;
	Hannoi(n-1, buffer, from, to);
}