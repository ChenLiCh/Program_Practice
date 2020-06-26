#include <iostream>
#include <cstdlib>

using namespace std;

template <class T> 
class ListNode {
    public:
        ListNode();
        ListNode(T value);
        ~ListNode();
        void SetLink(ListNode<T> *next);
        void SetData(T value);
        ListNode<T>* GetLink();
        T& GetData();
    private:
        T data;
        ListNode<T> *link;
};