#include <cassert>
#include <iostream>
#include <queue>
#include <vector>

#include "adjacency_matrix.h"


AdjacencyMatrix::AdjacencyMatrix(size_t num_vertices)
{
    if (num_vertices > MAX_SIZE)
        num_vertices = MAX_SIZE;

    vertices = num_vertices;

    // Allocate space for matrix
    matrix = new int* [num_vertices];

    for (size_t i = 0; i < num_vertices; i++) {
        matrix[i] = new int [num_vertices];

        // 0 out matrix
        for (size_t j = 0; j < num_vertices; j++)
            matrix[i][j] = 0;
    }
}

AdjacencyMatrix::~AdjacencyMatrix()
{
    for (size_t i = 0; i < vertices; i++)
        delete [] matrix[i];

    delete [] matrix;
}

void AdjacencyMatrix::addEdge(size_t v1, size_t v2, int weight) const
{
    assert(v1 <= vertices);
    assert(v2 <= vertices);

    matrix[v1][v2] = weight;
    matrix[v2][v1] = weight;
}

bool AdjacencyMatrix::isAdjacent(size_t v1, size_t v2) const
{
    assert(v1 <= vertices);
    assert(v2 <= vertices);

    return (matrix[v1][v2] == matrix[v2][v1]
         && matrix[v1][v2] != 0
         && matrix[v2][v1] != 0);
}

void AdjacencyMatrix::bfs(size_t start) const
{
    assert(start <= vertices);

    std::queue<size_t> q;
    std::vector<bool> visited{false};

    // Add vertex to queue and mark as visited
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        // Need to update current vertex each iteration
        start = q.front();

        // Add all adjacent, unvisited vertices to queue and mark them as
        // visited
        for (size_t i = 0; i < vertices; i++) {
            if (isAdjacent(start, i) && visited[i] == false) {
                q.push(i);
                visited[i] = true;
            }
        }

        // Process vertex (print to stdout in our case)
        std::cout << q.front() << " ";
        q.pop();
    }
}
