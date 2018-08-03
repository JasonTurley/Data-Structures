// Implementation of a hash table with seperate chaining collision strategy

#ifndef HASH_H
#define HASH_H

#include <array>
#include <string>

using std::string;

class Hash {
private:
    static const int table_size = 10;

    typedef struct item {
        string name;
        string color;
        item* next;
    } item;

    std::array<item*, table_size> hash_table;

public:
    // Constructor: initializes hash_table to empty values
    Hash();

    // Destructor: frees memory
    ~Hash();

    // Simple hash function: returns index based on key param
    int hash(string key);

    // Inserts item into proper slot in hash_table
    void insert(string name, string item);

    // Check if name is in hash_table
    bool search(string name);

    // Removes the first instance of an item from list
    bool remove(string name);

    // Helper functions

    bool remove(item** head_ref, string name);

    // Returns a pointer to an allocated and initialized item struct
    item* createItem(string name, string color);

    // Deletes an entire linked list
    void destroyList(item** head_ref);
};


#endif
