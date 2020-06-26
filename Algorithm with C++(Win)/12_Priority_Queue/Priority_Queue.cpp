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
    cout << "一個 Priority_Queue 解構了..." << endl <<endl;
}

template <class T>
void Priority_Queue<T>::Get_Front() {
    if (Is_Empty()) cout << "Priority_Queue 為空，沒有 front 元素" << endl << endl;
    else cout << "front 元素為： " << arr[front] << endl << endl;
}

template <class T>
void Priority_Queue<T>::Get_Rear() {
    if (Is_Empty()) cout << "Priority_Queue 為空，沒有 rear 元素" << endl << endl;
    else cout << "rear 元素為： " << arr[rear] << endl << endl;
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
    if (Is_Full()) cout << "Priority_Queue 已經滿了，無法新增元素..." << endl << endl;
    else {
        arr[rear] = element;
        cout << arr[rear] << " 被 Enqueue，現在有 ";
        rear = (rear + 1) % capacity; // 關鍵
        count++;
        cout << Get_Count() << " 個元素..." << endl << endl;
    }
}

template <class T>
void Priority_Queue<T>::Dequeue() {
    if (Is_Empty()) cout << "Priority_Queue 已經空了，無法刪除元素..." << endl << endl;
    else {
        int max_Index = 0; // 最大元素的索引
        for (i = 0; i < capacity; i++) if (arr[i] > arr[max_Index]) max_Index = i;

        
        cout << arr[front] << " 被 Dequeue，現在剩下 ";
        front = (front + 1) % capacity; // 關鍵
        count--;
        cout << Get_Count() << " 個元素..." << endl << endl;
    }
}