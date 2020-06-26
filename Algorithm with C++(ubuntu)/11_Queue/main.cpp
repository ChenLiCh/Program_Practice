#include <iostream>
#include <cstdlib>
#include "Queue.cpp"

using namespace std;

int main() {

    Queue<int> *queue = new Queue<int>(5);

    cout << "�{�b Queue �O�_���šH " << queue->Is_Empty() << endl << endl;

    queue->Enqueue(0);
    queue->Enqueue(1);
    queue->Enqueue(2);
    queue->Enqueue(3);
    queue->Enqueue(4);

    cout << "�{�b Queue �O�_�����H " << queue->Is_Full() << endl << endl;

    queue->Dequeue();
    queue->Dequeue();
    queue->Dequeue();
    queue->Dequeue();
    queue->Dequeue();
    cout << "�{�b Queue �O�_���šH " << queue->Is_Empty() << endl << endl;
    queue->Dequeue();

    queue->Enqueue(5);
    queue->Enqueue(6);
    queue->Enqueue(7);
    queue->Enqueue(8);
    queue->Enqueue(9);

    queue->Dequeue();
    queue->Dequeue();
    queue->Dequeue();
    queue->Enqueue(10);

    system("pause");
    return 0;
}