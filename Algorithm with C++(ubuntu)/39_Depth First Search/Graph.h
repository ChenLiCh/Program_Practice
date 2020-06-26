#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <cstdlib>
#include <list>

using namespace std;

class Graph {

    public:
        Graph() {}

        Graph(int v): v(v), adj(new list<int>[v]) {}

        // 把 Graph 的元素放進 adjacency list
        void Add_Edge(int v, int w) {
            adj[v].push_back(w);
        }

        // 深度優先搜尋
        void DFS(int s) {

            bool *visited = new bool[v];
            for (int i = 0; i < v; i++) visited[i] = false;
            DFSUtil(s, visited);
        }
        
    private:
        int v;          // vertices 的數量
        list<int> *adj; // 儲存 adjaency list

        void DFSUtil(int s, bool visited[]) {
            visited[s] = true;
            cout << s << " ";

            list<int>::iterator it;
            for (it = adj[s].begin(); it != adj[s].end(); it++)
                if (!visited[*it])
                    DFSUtil(*it, visited);
        }
};
#endif