#include <cstdlib>
#include <iostream>

#include "hash.h"

using std::string;
using std::cout;
using std::endl;

// Initialize hash_table with default values
Hash::Hash() {
    for (int i = 0; i < table_size; i++) {
        hash_table[i] = new item;
        hash_table[i]->name = "empty";
        hash_table[i]->color = "empty";
        hash_table[i]->next = nullptr;
    }
}

// TODO: finish me
Hash::~Hash() {

}

// Simple hash function: returns index based on key param
int Hash::hash(string key) {
    int hash = 0;

    // Sum character values
    for (int i = 0; i < (int) key.length(); i++) {
        hash += (int) key[i];
    }

    return hash % table_size;
}

// Inserts item into proper slot in hash_table
void Hash::insert(string name, string color) {
    int index = hash(name);

    if (hash_table[index]->name == "empty") {
        hash_table[index]->name = name;
        hash_table[index]->color = color;
        hash_table[index]->next = nullptr;


    } else {
        // Need to allocate new item
        item* new_item = createItem(name, color);
        item* ptr = hash_table[index];

        // Find empty position in bucket
        while (ptr->next != nullptr) {
            ptr = ptr->next;
        }

        ptr->next = new_item;
    }

    cout << "Inserted " << name << " at index " << index << endl;

}

// Check if name is in hash_table
bool Hash::search(string name) {
    // Do NOT search entire table, only look at lists in the hash index
    int index = hash(name);
    item* ptr = hash_table[index];

    // Linear search linked list of namespace
    while (ptr != nullptr) {
        if (ptr->name == name)
            return true;
        ptr = ptr->next;
    }

    // Did not find name
    return false;
}

Hash::item* Hash::createItem(string name, string color) {
    item *new_item = new item;
    new_item->name = name;
    new_item->color = color;
    new_item->next = nullptr;

    return new_item;
}
