#include "GraphMST.h"

using namespace std;

GraphMST::GraphMST(): num_Vertex(0) {

}

GraphMST::GraphMST(int n): num_Vertex(n) {

    adj_Matrix.resize(num_Vertex);
    for (int i = 0; i < num_Vertex; i++)
        adj_Matrix[i].resize(num_Vertex);
}

void GraphMST::Add_Edge(int from, int to, int weight) {

    adj_Matrix[from][to] = weight;
    adj_Matrix[to][from] = weight;
}


int Find_Set_and_Collapsing(int *subset, int i) {

    // find root
    int root = 0;
    for (root = i; subset[root] >= 0;)
        root = subset[root];
    
    // 把 subset[i] 的 parent、parent's parent...直接指向 root
    int parent = 0;
    while(i != root) {
        parent = subset[i];
        subset[i] = root;
        i = parent;
    }

    return root;
}

void Union_Set(int *subset, int x, int y) {
    
    int x_Root = Find_Set_and_Collapsing(subset, x);
    int y_Root = Find_Set_and_Collapsing(subset, y);

    if (subset[x_Root] <= subset[y_Root]) {
        subset[x_Root] += subset[y_Root];
        subset[y_Root] = x_Root;
    }
    else {
        subset[y_Root] += subset[x_Root];
        subset[x_Root] = y_Root;
    }
}

void GraphMST::KruskalMST() {

    Edge *edge_Set_MST = new Edge[num_Vertex - 1];
    int edge_Set_Count = 0;

    int subset[num_Vertex];
    for (int i = 0; i < num_Vertex; i++)
        subset[i] = -1;

    vector<Edge> increase_Weight;
    Get_Sorted_Edge(increase_Weight);

    for (int i = 0; i < increase_Weight.size(); i++) {
        if (Find_Set_and_Collapsing(subset, increase_Weight[i].from) != Find_Set_and_Collapsing(subset, increase_Weight[i].to)) {
            edge_Set_MST[edge_Set_Count++] = increase_Weight[i];
            Union_Set(subset, increase_Weight[i].from, increase_Weight[i].to);
        }
    }

    cout << setw(3) << "v1" << " - " << setw(3) << "v2"<< " : weight" << endl;
    for (int i = 0; i < num_Vertex - 1; i++) {
        cout << setw(3) << edge_Set_MST[i].from << " - " << setw(3) << edge_Set_MST[i].to 
             << " : " << setw(4) << edge_Set_MST[i].weight << endl;
    }
}

bool Compare_Weight(Edge e1, Edge e2) {
    return e1.weight < e2.weight;
}

void GraphMST::Get_Sorted_Edge(vector<Edge> &edge_Array) {

    for (int i = 0; i < num_Vertex - 1; i++)
        for (int j = i + 1; j < num_Vertex; j++)
            if (adj_Matrix[i][j] != 0)
                edge_Array.push_back(Edge(i, j, adj_Matrix[i][j]));
    
    // 由小排到大
    sort(edge_Array.begin(), edge_Array.end(), Compare_Weight);
}