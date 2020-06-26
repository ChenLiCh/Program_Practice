#include <iostream>
#include <cstdlib>

using namespace std;

template <class T>
class Priority_Queue {
    
    public:
        Priority_Queue();
        Priority_Queue(int);
        ~Priority_Queue();
        void Get_Front();
        void Get_Rear();
        int Get_Count();
        bool Is_Empty();
        bool Is_Full();
        void Enqueue(T);
        void Dequeue();
    private:
        int front, rear, count;
        unsigned capacity;
        T *arr;
};