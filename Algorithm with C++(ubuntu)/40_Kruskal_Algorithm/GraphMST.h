#ifndef GRAPHMST_H
#define GRAPHMST_H
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef struct Edge {

    int from, to, weight;
    Edge() {}
    Edge(int f, int t, int w): from(f), to(t), weight(w) {}
}Edge;

class GraphMST {

    public:
        GraphMST();
        GraphMST(int);
        
        void Add_Edge(int, int, int);
        void KruskalMST();
        void Get_Sorted_Edge(vector<Edge>&);

        friend int Find_Set_and_Collapsing(int*, int);
        friend void Union_Set(int*, int, int);
    private:
        int num_Vertex;
        vector<vector<int>> adj_Matrix;
};
#endif