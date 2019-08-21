#ifndef ADJACENCY_MATRIX_H
#define ADJACENCY_MATRIX_H

#include <cstddef>

#define MAX_SIZE (20)

/**
 * Represents an undirected graph as an adjacency matrix. Checking if any two
 * vertices are adjacent takes O(1) time. The space complexity is O(V * V),
 * where V is number of vertices.
 */
class AdjacencyMatrix {
public:
	/**
	 * Construct an AdjacencyMatrix to hold num_vertices vertices.
	 */
	AdjacencyMatrix(size_t num_vertices);

	/**
	 * Destroys memory associated with an AdjacencyMatrix.
	 */
	~AdjacencyMatrix();

	/**
	 * Creates an edge between vertices v1 and v2. Including a weight is
	 * optional.
	 */
	void addEdge(size_t v1, size_t v2, int weight = 1) const;

	/**
	 * Checks whether or not two vertices are adjacent.
	 */
	bool isAdjacent(size_t v1, size_t v2) const;

    /**
     * Performs a breadth first search (traversal) from the given vertex,
     * printing the graph to stdout.
     */
    void bfs(size_t start) const;

private:
	/**
	 * The number of vertices in the graph.
	 */
	size_t vertices;

	/**
	 * The adjacency matrix.
	 */
	int **matrix;
};

#endif // ADJACENCY_MATRIX_H
