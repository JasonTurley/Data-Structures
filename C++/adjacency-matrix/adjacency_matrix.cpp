#include <iostream>

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
        //for (size_t j = 0; j < num_vertices; j++)
        //    matrix[i][j] = 0;
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
    matrix[v1][v2] = weight;
    matrix[v2][v1] = weight;
}

bool AdjacencyMatrix::isAdjacent(size_t v1, size_t v2) const
{
    return (matrix[v1][v2] == matrix[v2][v1]
         && matrix[v1][v2] != 0
         && matrix[v2][v1] != 0);
}
