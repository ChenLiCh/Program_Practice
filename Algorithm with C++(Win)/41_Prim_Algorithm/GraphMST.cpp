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

int Min_Key_Extract(int *key, bool *visited, int size) {

    int min = MAX_Weight;
    int min_Index = 0;
    for (int i = 0; i < size; i++)
        if (visited[i] == false && key[i] < min)
            min = key[i], min_Index = i;

    return min_Index;
}

void GraphMST::PrimMST(int start = 0) {

    // 初始化 key[], predecessor[], visited[]
    int key[num_Vertex], predecessor[num_Vertex];
    bool visited[num_Vertex];
    for (int i = 0; i < num_Vertex; i++) {
        key[i] = MAX_Weight;
        predecessor[i] = -1;
        visited[i] = false;
    }

    key[start] = 0; // 起點的距離設為 0
    for (int i = 0; i < num_Vertex; i++) {
        int min_Key_Index = Min_Key_Extract(key, visited, num_Vertex);
        visited[min_Key_Index] = true;

        for (int j = 0; j < num_Vertex; j++) {
            if (visited[j] == false && adj_Matrix[min_Key_Index][j] != 0 && adj_Matrix[min_Key_Index][j] < key[j]) {
                predecessor[j] = min_Key_Index;
                key[j] = adj_Matrix[min_Key_Index][j];
            }
        }
    }

    // print MST, 與MST演算法主體無關
    cout << setw(3) << "v1" << " - " << setw(3) << "v2"<< " : weight" << endl;
    int i = (start + 1) % num_Vertex;   // 若從4開始, i依序為5,6,0,1,2,3
    while (i != start) {
        cout << setw(3) << predecessor[i] << " - " << setw(3) << i
                  << " : " << setw(4) << adj_Matrix[predecessor[i]][i] << endl;
        i = (++i) % num_Vertex;       // 到了6之後, 6+1 = 7, error:bad_access, 透過mod把7喬回0
    }
}