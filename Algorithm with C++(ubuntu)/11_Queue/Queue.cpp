#include "Queue.h"

template <class T>
Queue<T>::Queue(): front(0), rear(0), count(0), capacity(0), arr(NULL) {

}

template <class T>
Queue<T>::Queue(int c): front(0), rear(0), count(0), capacity(c), arr(NULL) {
    arr = new T[(capacity * sizeof(T))];
}

template <class T>
Queue<T>::~Queue() {
    cout << "�@�� Queue �Ѻc�F..." << endl <<endl;
}

template <class T>
void Queue<T>::Get_Front() {
    if (Is_Empty()) cout << "Queue ���šA�S�� front ����" << endl << endl;
    else cout << "front �������G " << arr[front] << endl << endl;
}

template <class T>
void Queue<T>::Get_Rear() {
    if (Is_Empty()) cout << "Queue ���šA�S�� rear ����" << endl << endl;
    else cout << "rear �������G " << arr[rear] << endl << endl;
}

template <class T>
int Queue<T>::Get_Count() {
    if (Is_Empty()) return 0;
    else return count;
}

template <class T>
bool Queue<T>::Is_Empty() {
    return count == 0;
}

template <class T>
bool Queue<T>::Is_Full() {
    return count == capacity;
}

template <class T>
void Queue<T>::Enqueue(T element) {
    if (Is_Full()) cout << "Queue �w�g���F�A�L�k�s�W����..." << endl << endl;
    else {
        arr[rear] = element;
        cout << arr[rear] << " �Q Enqueue�A�{�b�� ";
        rear = (rear + 1) % capacity; // ����
        count++;
        cout << Get_Count() << " �Ӥ���..." << endl << endl;
    }
}

template <class T>
void Queue<T>::Dequeue() {
    if (Is_Empty()) cout << "Queue �w�g�ŤF�A�L�k�R������..." << endl << endl;
    else {
        cout << arr[front] << " �Q dequeue�A�{�b�ѤU ";
        front = (front + 1) % capacity; // ����
        count--;
        cout << Get_Count() << " �Ӥ���..." << endl << endl;
    }
}