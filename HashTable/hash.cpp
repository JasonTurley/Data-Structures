#include <cstdlib>
#include <iostream>

#include "hash.h"

using std::string;
using std::cout;
using std::endl;

// Initialize hash_table with default values
Hash::Hash() {
    for (int i = 0; i < table_size; i++) {
        hash_table[i] = nullptr;
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
    item* new_item = createItem(name, color);
    int index = hash(name);

    if (hash_table[index] == nullptr) {
        // allocate new new_item
        hash_table[index] = new_item;
    } else {
        // insert at end of list
        item* ptr = hash_table[index];
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

// Removes the first instance of an item from list
bool Hash::remove(string name) {
    int index = hash(name);
    item* ptr = hash_table[index];

    return remove(&ptr, name);
}

bool Hash::remove(item** head, string name) {
    item* ptr = *head;

    if (*head) {
        if (ptr->name == (*head)->name) {
            *head = ptr->next;
            ptr->next = nullptr;
            delete(ptr);

            return true;
        }
    }

    while (ptr) {
        if (ptr->next->name == name) {
            item* to_delete = ptr->next;
            ptr->next = to_delete->next;
            to_delete->next = nullptr;
            delete(to_delete);

            return true;
        }

        ptr = ptr->next;
    }

    return false;
}

Hash::item* Hash::createItem(string name, string color) {
    item *new_item = new item;
    new_item->name = name;
    new_item->color = color;
    new_item->next = nullptr;

    return new_item;
}
