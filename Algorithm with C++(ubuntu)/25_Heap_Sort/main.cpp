// �ԲӸѻ�
// http://alrightchiu.github.io/SecondRound/priority-queuebinary-heap.html#other

#include <iostream>
#include <cstdlib>
#include "Heap.h"

using namespace std;

int main() {

	// �s�W�@�Ӱ�n
	Heap<char, int> new_Heap;
	new_Heap.Initial_Heap();

    new_Heap.Build_Min_Heap();
    

    // �s�W����
    new_Heap.Min_Heap_Insert('J', 3);
    new_Heap.Min_Heap_Insert('K', 99);
    new_Heap.Min_Heap_Insert('L', 78);

    new_Heap.Heap_Sort();

	system("pause");
	return 0;
}
