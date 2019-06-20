/**
 * Doubly Linked List implementation.
 */

#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>
#include <cstddef>	// size_t

using std::ostream;

#define LAST_NODE() (head == tail)	// Last node in linked list

template <class T>
class List {
 private:

	/**
	 * Represents a node within our linked list. Made private due to the rule of
	 * encapsulation -- the end user does not need to know the internal implementation.
	 */
	class ListNode {
	 public:
		/**
		 * Default constructor.
		 */
		ListNode();

		/**
		 * Constructs a ListNode from given data.
		 */
		ListNode(const T& ndata);

		const T data;

		ListNode *next;

		ListNode *prev;
	};

 public:
	/**
	 * Default constructor.
	 *
	 * Creates an empty List.
	 */
	List();

	/**
	 * Destructor.
	 *
	 * Frees memory of a List.
	 */
	~List();

	/**
	 * Overloaded output stream operator.
	 * Prints the contents of the list from head to tail.
	 */
	friend ostream& operator<<(ostream& os, const List<T> &list)
	{
		list.print(os);
		return os;
	}

	/**
	 * Returns the size of the current List.
	 * Const because it will not modify the List.
	 */
	size_t size() const;

	/**
	 * Returns whether or not the list is empty.
	 * Const because it will not modify the List.
	 */
	bool empty() const;

	/**
	 * Returns the data at the head of the list, or T() if it
	 * is empty.
	 * Const because it will not modify the List.
	 */
	const T front() const;

	/**
	 * Returns the data at the tail of the list, or T() if it
	 * is empty.
	 * Const because it will not modify the List.
	 */
	const T back() const;

	/**
	 * Prints the contents of the List to stdout.
	 * Const because it will not modify the List.
	 */
	void print(ostream& os) const;

	/**
	 * Inserts data at given index, with 0 being the head.
	 */
	void insertAt(const T& ndata, size_t index);

	/**
	 * Adds data to the head of the List.
	 */
	void insertFront(const T& ndata);

	/**
	 * Adds data to the tail of the List.
	 */
	void insertBack(const T& ndata);

	/**
	 * Removes and returns the element at the given index.
	 */
	const T eraseFrom(size_t index);

	/**
	 * Removes and returns the element at the head of the List.
	 */
	const T popFront();

	/**
	 * Removes and returns the element at the end of the List.
	 */
	const T popBack();

	/**
	 * Removes the first node with the given value.
	 */
	void removeValue(const T& value);

	/**
	 * Returns the value at the given index, starting at 0.
	 * Const because it will not modify the List.
	 */
	const T valueAt(size_t index) const;
	/**
	 * Reverses the current list.
	 */
	void reverse();

 private:
	/**
	 * Private member variables.
	 */

	/**
	 * Head of the List.
	 * Points to the first element or NULL if list is empty.
	 */
	ListNode *head;

	/**
	 * The tail of the List.
	 * Points to the last element or NULL if list is empty.
	 */
	ListNode *tail;

	/**
	 * The current number of ListNodes in the List.
	 */
	size_t  length;

	/**
	 * Private helper functions.
	 */

	/**
	 * Unlinks given node from list, does not delete it.
	 */
	void unlink(ListNode*& ptr);

	/**
	 * Destroys all dynamically allocated memory associated with the current List.
	 */
	void clear();

	/**
	 * Helper function to reverse the linked list.
	 */
	void reverse(ListNode*& start, ListNode*& end);
};

#endif // _LIST_H_
