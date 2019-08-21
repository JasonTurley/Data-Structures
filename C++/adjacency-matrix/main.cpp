#include <iostream>

#include "adjacency_matrix.h"

using std::cout;

void testBFS()
{
    AdjacencyMatrix adj(5);

    adj.addEdge(0, 2);
    adj.addEdge(0, 4);
    adj.addEdge(1, 2);
    adj.addEdge(1, 3);
    adj.addEdge(1, 4);
    adj.addEdge(2, 0);
    adj.addEdge(2, 1);
    adj.addEdge(2, 3);
    adj.addEdge(3, 1);
    adj.addEdge(3, 2);
    adj.addEdge(3, 4);
    adj.addEdge(4, 0);
    adj.addEdge(4, 1);
    adj.addEdge(4, 3);

    size_t starting_vertex = 0;

    cout << "Breadth First Search from vertex " << starting_vertex << ": ";
    adj.bfs(starting_vertex);
    cout << "\n";
}

void testAll()
{
    testBFS();
}

int main()
{
    testAll();

    return 0;
}
