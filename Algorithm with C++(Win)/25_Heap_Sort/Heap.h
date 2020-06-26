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

        // ��l��
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

            // �W�X���
            if (left > length || right > length) return;
            
            // root �M���l��H�Υk�l���j�p
            if (heap[left].Get_Key() < heap[root].Get_Key())  smallest = left;
            if (heap[right].Get_Key() < heap[smallest].Get_Key()) smallest = right;
            
            // �ݭn�洫
            if (smallest != root) {
                Swap(heap[smallest], heap[root]);
                Min_Heapify(smallest, length);
            }
        }

        // �� Node[i] ~ Node[n/2-1] �`�I�� Heapify
        // i = 0, n: �`�`�I�ƶq
        // �]���u�� Node[i] ~ Node[n/2-1] �`�I���l�`�I
        void Build_Min_Heap() {
            for (int i = heap.size() / 2 - 1; i >= 0; i--) Min_Heapify(i, heap.size()-1);
            Print("Build_Min_Heap");
        }

        // �^�� key �ȳ̤p�� element
        T1 Minimum() {
            return heap[0].Get_Element();
        }

        // ���X key �ȳ̤p�� Node�A�ñq vector ���R��
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

        // �u���C�v key ��
        void Decrease_Key(T1 e, T2 new_Key) {

            int index = Find_Position(e);

            // �p�G���O��node��Key�U��, �K�פ�禡
            if (new_Key > heap[index].Get_Key()) {
                cout << "New key is larger than current key..." << endl << endl;
                return;
            }

            // ��sKey��, �ݭn�ˬd�O�_�s��subtree����Min Heap
            heap[index].Set_Key(new_Key);
    
            while (index > 0 && heap[Get_Parent_Index(index)].Get_Key() > heap[index].Get_Key()) {
                Swap(heap[index], heap[Get_Parent_Index(index)]);
                index = Get_Parent_Index(index);
            }
        }

        // �b��n�������s�W Node�A�ýվ��m
        void Min_Heap_Insert(T1 e, T2 k) {
            
            heap.push_back(Node<T1, T2>(e, k));
            Print("Min_Heap_Insert...");
            Decrease_Key(e, k);
            Print("Min_Heap_Insert...");
        }
        
        // ����n�Ƨ�(�p->�j)
        void Heap_Sort() {
            vector<Node<T1, T2>> sort_Vector;
            while(!Is_Empty()) sort_Vector.push_back(Extract_Min());
            cout << "Heap_Sort..." << endl;
            for (vector<Node<char, int>>::iterator it = sort_Vector.begin(); it != sort_Vector.end(); it++)
                cout << "Node " << it->Get_Element() << " �� key �Ȭ� " << it->Get_Key() << endl;
            cout << endl;
        }

        void Print(string str) {
            cout << str << endl;
            for (vector<Node<char, int>>::iterator it = heap.begin(); it != heap.end(); it++)
                cout << "Node " << it->Get_Element() << " �� key �Ȭ� " << it->Get_Key() << endl;
            cout << endl;
        }

    private:
	    vector<Node<T1, T2>> heap;
        bool Is_Empty() {
            return heap.size() == 0;
        }

        // �洫2�� Node
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