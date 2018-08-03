#include <cstdlib>
#include <iostream>

#include "hash.h"

using std::string;
using std::cout;
using std::endl;


HashTable::HashTable() {
    for (int i = 0; i < table_size; i++) {
        hash_table[i] = nullptr;
    }
}

HashTable::~HashTable() {
    for (int i = 0; i < table_size; i++) {
        Node* head = hash_table[i];
        destroyList(&head);
    }
}

int HashTable::hash(string key) {
    int hash = 0;

    // Sum character values
    for (int i = 0; i < (int) key.length(); i++) {
        hash += (int) key[i];
    }

    return hash % table_size;
}

void HashTable::insert(string key, string value) {
    Node* node = new Node(key, value);
    int index = hash(key);

    // Insert node into first empty slot
    if (hash_table[index] == nullptr) {
        hash_table[index] = node;
    } else {
        Node* ptr = hash_table[index];
        while (ptr->next != nullptr) {
            ptr = ptr->next;
        }
        ptr->next = node;
    }

    elems++;
}

bool HashTable::search(string key) {
    // Only search one slot, not the entire table
    int index = hash(key);

    Node* ptr = hash_table[index];
    while (ptr != nullptr) {
        if (ptr->key == key)
            return true;
        ptr = ptr->next;
    }

    // Did not find key
    return false;
}

bool HashTable::remove(string key) {
    int index = hash(key);
    Node* ptr = hash_table[index];

    return remove(&ptr, key);
}

bool HashTable::remove(Node** head, string target) {
    Node* ptr = *head;

    if (*head) {
        // Special case: deleting head of list
        if (ptr->key == target) {
            if (ptr->next) {
                *head = ptr->next;
                ptr->next = nullptr;
            }
            delete(ptr);
            return true;
        }
    }

    // Search for target
    while (ptr) {
        if (ptr->next->key == target) {
            Node* to_delete = ptr->next;
            ptr->next = to_delete->next;
            to_delete->next = nullptr;
            delete(to_delete);
            return true;
        }

        ptr = ptr->next;
    }

    return false;
}

void HashTable::destroyList(Node** head_ref) {
    while (*head_ref) {
        Node* ptr = *head_ref;
        *head_ref = ptr->next;
        ptr->next = nullptr;
        delete(ptr);
    }
    if (*head_ref)
        *head_ref = nullptr;
}
