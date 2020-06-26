#ifndef GRAPHMST_H
#define GRAPHMST_H
#include <iostream>
#include <cstdlib>
#include <vector>
#include <iomanip>
#define MAX_Weight 1000;

using namespace std;

class GraphMST {

    public:
        GraphMST();
        GraphMST(int);
        
        void Add_Edge(int, int, int);
        void PrimMST(int);
        
        friend int Min_Key_Extract(int *, bool *, int);
    private:
        int num_Vertex;
        vector<vector<int>> adj_Matrix;
};
#endif