// Class for a binary search tree
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <stdio.h>

	/* Represents a tree Node */
	typedef struct Node {
		int data;		/* data item */
		struct Node *parent;	/* (optional) pointer to parent */
		struct Node *left;	/* pointer to left child */
		struct Node *right;	/* pointer to right child */
	} Node;	

/* Function declarations */
struct Node *search(struct Node *root, int x);
struct Node *findMin(struct Node *root);
struct Node *findMax(struct Node *root);
int max_height(struct Node *root);
int min_height(struct Node *root);
int countLeaves(struct Node *root);
int levelOrderTraversal(struct Node *root);
void printPaths(struct Node *root);
void printPathsRecur(struct Node *root, int path[], int pathLen);

/* Helper functions */
int min(int x, int y) { return (x < y) ? x : y; }
int max(int x, int y) { return (x > y) ? x : y; }
void printPathsRecur(struct Node *root, int path[], int pathLen);
void printArray(int arr[], int size);


#endif

















