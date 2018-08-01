/**
 * @file heap.h - Header file for min-heap data structure
 *
 * @date (created) 31 July 2018
 */

#ifndef HEAP_H
#define HEAP_H

class Heap {
    public:
        /**
         * Returns the heap's smallest value, without changing the heap structure.
         * This is a O(1) operation.
         *
         * @return The minimum heap value.
         */
        int getMin() const;

        /**
         * Inserts value into the end of the heap. Calls helper function
         * heapifyUp() if the heap's order is distorted. This is a worst
         * case O(logN) operation.
         */
        void insert(int value) const;

        /**
         * Returns the number of elements in the heap.
         *
         * @return Size of heap.
         */
        size_t size();

    private:
        /**
         * Maintains min-heap property by making sure the parent node is always
         * less than its children nodes.
         */
        void heapifyUp(size_t currentIndex);

        /**
         * Swaps the data of two variables.
         */
        void swap(int &x, int &y);

        /**
         * Container for our min-heap
         */
        std::vector<int> elements;

        /**
         * The current size of our heap.
         */
        size_t size;
};

#endif
