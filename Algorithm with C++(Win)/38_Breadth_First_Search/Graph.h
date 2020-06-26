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
            if (adj[v].empty()) adj[v].push_back(v);
            adj[v].push_back(w);
        }

        // 廣度優先搜尋
        void BFS(int s) {

            // 紀錄是否尋訪過
            bool *visited = new bool[v];
            for (int i = 0; i < v; i++) visited[i] = false;

            // 記錄從起點 s 到任意點的 distance
            int *distance = new int[v];

            // 把起點 s 放入 queue 中，並且設定為已經 visit
            list<int> queue;
            visited[s] = true;
            queue.push_back(s);
            distance[s] = 0;
            
            list<int>::iterator it, head;

            while(!queue.empty()) {

                // 把 queue 中的第一個元素 pop
                s = queue.front();
                cout << s << " ";
                queue.pop_front();

                // 尋訪以 s 為頭的 adjaency list
                head = adj[s].begin();
                for (it = adj[s].begin(); it !=adj[s].end(); it++) {
                    if (!visited[*it]) {
                        visited[*it] = true;
                        queue.push_back(*it);
                        distance[*it] = distance[*head] + 1;
                    }
                }

            }
            cout << endl;
            for (int i = 0; i < v; i++) cout << distance[i] << " ";
        }
        
    private:
        int v;          // vertices 的數量
        list<int> *adj; // 儲存 adjaency list
};
#endif