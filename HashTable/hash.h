/**
 * @file hash.h
 * Definition for the hash table class
 */

#ifndef HASH_H
#define HASH_H

#include <cstddef>  // size_t
#include <array>
#include <string>

using std::string;

/**
 * HashTableTable: Implementation of a hash table with seperate chaining collision strategy
 */
 
class HashTable {
private:

    /**
     * Node: encapsulated data stored in the hash table
     */
    typedef struct Node {
        string key;
        string value;
        Node* next;

        /**
         * Node constructor
         */
        Node(string k, string v)
            : key(k), value(v), next(nullptr)
        {           
            // nothing
        }

    } Node;

    /** 
     * The number of cells in our hash table 
     */
    static const int table_size = 10; 

    /**
     * The number of elements in our hash table
     */
    std::size_t elems;

    /**
     * Container where hash table elements are stored
     */
    std::array<Node*, table_size> hash_table;

public:
    /**
     * Constructor: creates an empty hash table
     */
    HashTable();

    /**
     * Destructor: releases all memory stored in the hash table
     */
    ~HashTable();

    /*
     * Computes an index based on the given key.
     *
     * @param key The data to hash
     * @return An index for the hash table
     */
    int hash(string key);

    /**
     * Inserts the given key-value pair into the proper hash table index.
     *
     * @param key The lookup Node
     * @param value The data associated with key
     */
    void insert(string key, string value);

    /*
     * Check if the key is present in the hash table
     *
     * @param key The lookup Node
     * @return Whether or not the Node is in the table
     */
    bool search(string key);

    /**
     * Removes the first occurance of an Node from the hash table.
     *
     * @param key The lookup Node
     * @return Whether or not the key was successfully removed
     */
    bool remove(string key);

    /**
     * Helper functions
     */

    /**
     * Removes a node from the linked list.
     *
     * @param head_ref A pointer to the head of the linked list.
     * @param key The Node to search for
     * @return Whether or not the Node was successfully removed
     */
    bool remove(Node** head_ref, string key);

    /**
     * Creates a new node.
     *
     * @param key
     * @param value
     * @return A pointer to an initialized node
     */
    Node* createItem(string key, string value);

    /**
     * Releases memory from a singly-linked list of nodes
     *
     * @note needs to be called on every cell of the hash table
     *
     * @param head_ref A pointer to the head of the linked list
     */
    void destroyList(Node** head_ref);
};


#endif
