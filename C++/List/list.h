/**
 * Doubly Linked List implementation.
 */

#ifndef _LIST_H_
#define _LIST_H_

using namespace std;

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
	 * Returns the size of the current List.
	 * Const because it will not modify the List.
	 */
	int size() const;

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
	void print() const;

	/**
	 * Adds data to the head of the List.
	 */
	void insertFront(const T& ndata);

	/**
	 * Adds data to the tail of the List.
	 */
	void insertBack(const T& ndata);

	/**
	 * Removes and returns the element at the head of the List.
	 */
	const T popFront();

	/**
	 * Removes and returns the element at the end of the List.
	 */
	const T popBack();


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
	int length;

	/**
	 * Private helper functions.
	 */

	/**
	 * Destroys all dynamically allocated memory associated with the current List.
	 */
	void clear();

};

#endif // _LIST_H_
