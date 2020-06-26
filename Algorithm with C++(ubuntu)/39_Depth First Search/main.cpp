#include <iostream>
#include <cstdlib>
#include "Graph.h"

using namespace std;

int main() {

    Graph g(4); 
    g.Add_Edge(0, 1); 
    g.Add_Edge(0, 2); 
    g.Add_Edge(1, 2); 
    g.Add_Edge(2, 0); 
    g.Add_Edge(2, 3); 
    g.Add_Edge(3, 3); 

    g.DFS(2);

    system("pause");
    return 0;
}