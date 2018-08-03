#include <cstdlib>
#include <iostream>

#include "hashtable.h"

using std::string;
using std::cout;
using std::endl;


HashTable::HashTable() {
    for (int i = 0; i < table_size; i++) {
        hash_table[i] = nullptr;
    }

    elems = 0;
}

HashTable::~HashTable() {
    Node* head;

    for (int i = 0; i < table_size; i++) {
        head = hash_table[i];
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
    Node* head = hash_table[index];

    if (remove(&head, key)) 
        elems--;    
}

bool HashTable::remove(Node** head, string target) {
    Node* ptr = *head;

    // Special case: deleting head of list
    if (ptr && ptr->key == target) {
        *head = ptr->next;      // change head
         delete(ptr);           // delete old head
         ptr = nullptr;
         return true;
    }

    // Search for target
    Node *prev;

    while (ptr && ptr->key != target) {
        prev = ptr;
        ptr = ptr->next;
    }

    // If the target was not found
    if (!ptr) return false;

    prev->next = ptr->next;
    delete(ptr);
    ptr = nullptr;

    return true;
}

void HashTable::destroyList(Node** head_ref) {
    if (*head_ref)
        return;

    Node* curr = *head_ref;
    Node* next;

    while (curr) {
        next = curr->next;
        curr->next = nullptr;
        delete(curr);
        curr = next;
    }

    *head_ref = nullptr;
}
