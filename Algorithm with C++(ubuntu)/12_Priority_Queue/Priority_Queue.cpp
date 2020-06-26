#include "Priority_Queue.h"

template <class T>
Priority_Queue<T>::Priority_Queue(): front(0), rear(0), count(0), capacity(0), arr(NULL) {

}

template <class T>
Priority_Queue<T>::Priority_Queue(int c): front(0), rear(0), count(0), capacity(c), arr(NULL) {
    arr = new T[(capacity * sizeof(T))];
}

template <class T>
Priority_Queue<T>::~Priority_Queue() {
    cout << "�@�� Priority_Queue �Ѻc�F..." << endl <<endl;
}

template <class T>
void Priority_Queue<T>::Get_Front() {
    if (Is_Empty()) cout << "Priority_Queue ���šA�S�� front ����" << endl << endl;
    else cout << "front �������G " << arr[front] << endl << endl;
}

template <class T>
void Priority_Queue<T>::Get_Rear() {
    if (Is_Empty()) cout << "Priority_Queue ���šA�S�� rear ����" << endl << endl;
    else cout << "rear �������G " << arr[rear] << endl << endl;
}

template <class T>
int Priority_Queue<T>::Get_Count() {
    if (Is_Empty()) return 0;
    else return count;
}

template <class T>
bool Priority_Queue<T>::Is_Empty() {
    return count == 0;
}

template <class T>
bool Priority_Queue<T>::Is_Full() {
    return count == capacity;
}

template <class T>
void Priority_Queue<T>::Enqueue(T element) {
    if (Is_Full()) cout << "Priority_Queue �w�g���F�A�L�k�s�W����..." << endl << endl;
    else {
        arr[rear] = element;
        cout << arr[rear] << " �Q Enqueue�A�{�b�� ";
        rear = (rear + 1) % capacity; // ����
        count++;
        cout << Get_Count() << " �Ӥ���..." << endl << endl;
    }
}

template <class T>
void Priority_Queue<T>::Dequeue() {
    if (Is_Empty()) cout << "Priority_Queue �w�g�ŤF�A�L�k�R������..." << endl << endl;
    else {
        int max_Index = 0; // �̤j����������
        for (i = 0; i < capacity; i++) if (arr[i] > arr[max_Index]) max_Index = i;

        
        cout << arr[front] << " �Q Dequeue�A�{�b�ѤU ";
        front = (front + 1) % capacity; // ����
        count--;
        cout << Get_Count() << " �Ӥ���..." << endl << endl;
    }
}