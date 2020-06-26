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

        // �� Graph ��������i adjacency list
        void Add_Edge(int v, int w) {
            if (adj[v].empty()) adj[v].push_back(v);
            adj[v].push_back(w);
        }

        // �s���u���j�M
        void BFS(int s) {

            // �����O�_�M�X�L
            bool *visited = new bool[v];
            for (int i = 0; i < v; i++) visited[i] = false;

            // �O���q�_�I s ����N�I�� distance
            int *distance = new int[v];

            // ��_�I s ��J queue ���A�åB�]�w���w�g visit
            list<int> queue;
            visited[s] = true;
            queue.push_back(s);
            distance[s] = 0;
            
            list<int>::iterator it, head;

            while(!queue.empty()) {

                // �� queue �����Ĥ@�Ӥ��� pop
                s = queue.front();
                cout << s << " ";
                queue.pop_front();

                // �M�X�H s ���Y�� adjaency list
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
        int v;          // vertices ���ƶq
        list<int> *adj; // �x�s adjaency list
};
#endif