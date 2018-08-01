/**
 * @file heap.h - Blueprint for a heap class
 * 
 * @date (created) 31 July 2018
 */

#ifndef HEAP_H
#define HEAP_H

#include <cstddef>      // size_t
#include <vector>

using std::vector;

/**
 * Heap: a min-heap that can implement a priority queue
 */
class Heap {
    public:
        /**
         * Construct an empty heap
         */
        Heap();
        
        /**
         * Returns the heap's smallest value, without changing the heap 
         * structure in any way.
         * This is a O(1) operation.
         *
         * @return The minimum heap value.
         */
        int getMin() const;

        /**
         * Inserts a value into the heap while restoring the heap's property. 
         * This is a worst case O(logN) operation.
         *
         * @param value The data to insert into the heap
         */
        void insert(const int& value);

        /**
         * Returns the size of the heap.
         *
         * @return The number of elements in the heap.
         */
        size_t size() const;

    private:
        /**
         * Helper function to restore heap property by bubbling up the
         * smaller node to the top as necessary.
         *
         * @param currentIndex The index of the node that is rising up
         * the tree.
         */
        void heapifyUp(size_t currentIndex);

        /**
         * Swaps the data of two variables.
         *
         * @param x The value to store in y
         * @param y The value to store in x
         */
        void swap(int &x, int &y);

        /**
         * Container for this min-heap. Note, the heap starts at index(0) 
         */
        vector<int> elements;

        /**
         * The current size of our heap.
         */
        size_t length;
};

#endif
