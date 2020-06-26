#ifndef HEAP_H
#define HEAP_H
#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
#include "Node.h"

using namespace std;

template<class T1, class T2>
class Heap {

    public:
        Heap() {}
        ~Heap() {}

        // 初始化
        void Initial_Heap() {

            Node<T1, T2>* new_Node = new Node<T1, T2>('A', 10);
            heap.push_back(*new_Node);

            new_Node = new Node<T1, T2>('B', 100);
            heap.push_back(*new_Node);

            new_Node = new Node<T1, T2>('C', 2);
            heap.push_back(*new_Node);

            new_Node = new Node<T1, T2>('D', 77);
            heap.push_back(*new_Node);

            new_Node = new Node<T1, T2>('E', 6);
            heap.push_back(*new_Node);

            new_Node = new Node<T1, T2>('F', 60);
            heap.push_back(*new_Node);

            new_Node = new Node<T1, T2>('G', 85);
            heap.push_back(*new_Node);

            new_Node = new Node<T1, T2>('H', 5);
            heap.push_back(*new_Node);

            new_Node = new Node<T1, T2>('I', 1);
            heap.push_back(*new_Node);

            Print("Initial...");
        }
        
        void Min_Heapify(int root, int length) {

            int left = 0, right = 0, smallest = 0;
            smallest = root;
            left = root * 2 + 1;
            right = root * 2 + 2;

            // 超出邊界
            if (left > length || right > length) return;
            
            // root 和左子樹以及右子樹比大小
            if (heap[left].Get_Key() < heap[root].Get_Key())  smallest = left;
            if (heap[right].Get_Key() < heap[smallest].Get_Key()) smallest = right;
            
            // 需要交換
            if (smallest != root) {
                Swap(heap[smallest], heap[root]);
                Min_Heapify(smallest, length);
            }
        }

        // 把 Node[i] ~ Node[n/2-1] 節點做 Heapify
        // i = 0, n: 總節點數量
        // 因為只有 Node[i] ~ Node[n/2-1] 節點有子節點
        void Build_Min_Heap() {
            for (int i = heap.size() / 2 - 1; i >= 0; i--) Min_Heapify(i, heap.size()-1);
            Print("Build_Min_Heap");
        }

        // 回傳 key 值最小的 element
        T1 Minimum() {
            return heap[0].Get_Element();
        }

        // 取出 key 值最小的 Node，並從 vector 中刪除
        Node<T1, T2> Extract_Min() {

            if (Is_Empty()) {
                cout << "Error: Heap is empty..." << endl << endl;
                exit(-1);
            }

            Node<T1, T2> min = heap[0];   
            heap[0] = heap[heap.size() - 1];
            heap.erase(heap.begin() + heap.size() - 1);
            Min_Heapify(0, heap.size());
            
            return min;
        }

        // 「降低」 key 值
        void Decrease_Key(T1 e, T2 new_Key) {

            int index = Find_Position(e);

            // 如果不是把node的Key下修, 便終止此函式
            if (new_Key > heap[index].Get_Key()) {
                cout << "New key is larger than current key..." << endl << endl;
                return;
            }

            // 更新Key後, 需要檢查是否新的subtree滿足Min Heap
            heap[index].Set_Key(new_Key);
    
            while (index > 0 && heap[Get_Parent_Index(index)].Get_Key() > heap[index].Get_Key()) {
                Swap(heap[index], heap[Get_Parent_Index(index)]);
                index = Get_Parent_Index(index);
            }
        }

        // 在堆積的尾部新增 Node，並調整位置
        void Min_Heap_Insert(T1 e, T2 k) {
            
            heap.push_back(Node<T1, T2>(e, k));
            Print("Min_Heap_Insert...");
            Decrease_Key(e, k);
            Print("Min_Heap_Insert...");
        }
        
        // 做堆積排序(小->大)
        void Heap_Sort() {
            vector<Node<T1, T2>> sort_Vector;
            while(!Is_Empty()) sort_Vector.push_back(Extract_Min());
            cout << "Heap_Sort..." << endl;
            for (vector<Node<char, int>>::iterator it = sort_Vector.begin(); it != sort_Vector.end(); it++)
                cout << "Node " << it->Get_Element() << " 的 key 值為 " << it->Get_Key() << endl;
            cout << endl;
        }

        void Print(string str) {
            cout << str << endl;
            for (vector<Node<char, int>>::iterator it = heap.begin(); it != heap.end(); it++)
                cout << "Node " << it->Get_Element() << " 的 key 值為 " << it->Get_Key() << endl;
            cout << endl;
        }

    private:
	    vector<Node<T1, T2>> heap;
        bool Is_Empty() {
            return heap.size() == 0;
        }

        // 交換2個 Node
        void Swap(Node<T1, T2> &n1, Node<T1, T2> &n2) {
            Node<T1, T2> temp = n1;
            n1 = n2;
            n2 = temp;
        }

        int Find_Position(T1 e) {
            for (int i = 0; i < heap.size(); i++) if (heap[i].Get_Element() == e) return i;
        }

        int Get_Parent_Index(int i) {
            if (i % 2 == 0) return (i - 2) / 2;
            else return (i - 1) / 2;
        }
};
#endif