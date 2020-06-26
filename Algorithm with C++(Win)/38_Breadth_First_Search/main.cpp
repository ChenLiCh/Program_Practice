#include <iostream>
#include <cstdlib>
#include "Graph.h"

using namespace std;

int main() {

    Graph g(9);
    g.Add_Edge(0, 1);g.Add_Edge(0, 2);g.Add_Edge(0, 3);
    g.Add_Edge(1, 0);g.Add_Edge(1, 4);
    g.Add_Edge(2, 0);g.Add_Edge(2, 4);g.Add_Edge(2, 5);g.Add_Edge(2, 6);g.Add_Edge(2, 7);
    g.Add_Edge(3, 0);g.Add_Edge(3, 7);
    g.Add_Edge(4, 1);g.Add_Edge(4, 2);g.Add_Edge(4, 5);
    g.Add_Edge(5, 2);g.Add_Edge(5, 4);g.Add_Edge(5, 8);
    g.Add_Edge(6, 2);g.Add_Edge(6, 7);g.Add_Edge(6, 8);
    g.Add_Edge(7, 2);g.Add_Edge(7, 3);g.Add_Edge(7, 6);
    g.Add_Edge(8, 5);g.Add_Edge(8, 6);

    g.BFS(0);

    system("pause");
    return 0;
}