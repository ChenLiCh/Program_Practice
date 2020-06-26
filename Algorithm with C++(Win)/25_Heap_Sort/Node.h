#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cstdlib>

using namespace std;

template<class T1, class T2>
class Node {
public:
	Node() {}
	Node(T1 e, T2 k) : element(e), key(k) {}
	~Node() {
		//cout << "destroy..." << endl << endl;
	}

	void Set_Element(T1 e) {
		element = e;
	}
	
	void Set_Key(T2 k) {
		key = k;
	}
	
	T1 Get_Element() {
		return element;
	}
	
	T2 Get_Key() {
		return key;
	}
private:
	T1 element;
	T2 key;
};
#endif