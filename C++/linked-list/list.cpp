#include <iostream>

#include "list.h"

using std::ostream;
using std::cerr;
using std::endl;

// List constructor
template <class T>
List<T>::List()
    : head(nullptr), tail(nullptr), length(0)
{
}

template <class T>
List<T>::~List()
{
    clear();
}

template <class T>
void List<T>::clear()
{
    while (!empty())
        popFront();
}

template <class T>
void List<T>::unlink(ListNode*& ptr)
{
	if (ptr) {
		if (ptr->prev)
			ptr->prev->next = ptr->next;

		if (ptr->next)
			ptr->next->prev = ptr->prev;

		ptr->next = ptr->prev = nullptr;
	}
}

template <class T>
void List<T>::walk(ListNode*& ptr, size_t index) const
{
    if (index > length-1) {
        cerr << "index " << index << " is out of bounds" << endl;
        ptr = nullptr;

        return;

	// Traverse from tail if index is closer to the end,
	// otherwise start at head
    } else if (index >= length / 2) {
        ptr = tail;

        for (size_t i = length-1; i > index; i--)
                        ptr = ptr->prev;
    } else {
        ptr = head;

        for (size_t i = 0; i < index; i++)
            ptr = ptr->next;
    }
}

// ListNode constructor
template <class T>
List<T>::ListNode::ListNode()
    : data(T()), next(nullptr), prev(nullptr)
{
}

template <class T>
List<T>::ListNode::ListNode(const T& ndata)
    : data(ndata), next(nullptr), prev(nullptr)
{
}

template <class T>
size_t List<T>::size() const
{
    return length;
}

template <class T>
bool List<T>::empty() const
{
    return (!head && !tail && !length);
}

template <class T>
const T List<T>::front() const
{
    return (head) ? head->data : T();
}

template <class T>
const T List<T>::back() const
{
    return (tail) ? tail->data : T();
}


template <class T>
void List<T>::print(ostream& os) const
{
	os << "< ";
    ListNode *temp = head;

    while (temp) {
        os << temp->data << " ";
        temp = temp->next;
    }

    os << ">";
}

template <class T>
void List<T>::insertAt(const T& ndata, size_t index)
{
    ListNode *temp = new ListNode(ndata);

    if (empty()) {
        head = tail = temp;
    } else {
        // Insert at head
        if (index == 0) {
            temp->next = head;
            head->prev = temp;
            head = temp;
        // Insert at tail
        } else if (index >= size()) {
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        // Insert at index
        } else {
            // Get pointer to node at index
            ListNode *ptr = nullptr;

            walk(ptr, index);

            // Insert new node in front of ptr
            temp->next = ptr;
            temp->prev = ptr->prev;
            ptr->prev = temp;

            if (temp->prev)
                temp->prev->next = temp;
        }
    }

    length++;
}

template <class T>
void List<T>::insertFront(const T& ndata)
{
    insertAt(ndata, 0);
}

template <class T>
void List<T>::insertBack(const T& ndata)
{
    insertAt(ndata, length);
}

template <class T>
const T List<T>::eraseFrom(size_t index)
{
    ListNode *ptr = nullptr;
    T retval = T();

    if (empty())
        return retval;

    // Remove from head
    if (index == 0) {
        ptr = head;

        if (LAST_NODE())
            head = tail = nullptr;
        else
            head = head->next;

    // Remove from tail. Needed to maintain O(1) removal from end
    } else if (index >= length - 1) {
        ptr = tail;

        if (LAST_NODE())
            head = tail = nullptr;
        else
            tail = tail->prev;

    // Remove from index
    } else {
        walk(ptr, index);
		unlink(ptr);
    }

    retval = ptr->data;
    delete ptr;
    ptr = nullptr;

    length--;

    return retval;
}

template <class T>
const T List<T>::popFront()
{
    return eraseFrom(0);
}

template <class T>
const T List<T>::popBack()
{
    return eraseFrom(length);
}

template <class T>
void List<T>::removeValue(const T& value)
{
    ListNode *ptr = head;

    while (ptr && ptr->data != value)
        ptr = ptr->next;

    if (ptr) {
        unlink(ptr);
        delete ptr;

        if (LAST_NODE())
            head = tail = nullptr;

        length--;
    }
}

template <class T>
const T List<T>::valueAt(size_t index) const
{
    ListNode *ptr;
	walk(ptr, index);

    return (ptr) ? ptr->data : T();
}

template <class T>
void List<T>::reverse()
{
    reverse(head, tail);
}

template <class T>
void List<T>::reverse(ListNode*& start, ListNode*& end)
{
    ListNode *curr = start;
    ListNode *next;

    while (curr) {
        next = curr->next;
        curr->next = curr->prev;
        curr->prev = next;
        curr = next;
    }

    std::swap(start, end);
}

// Declare intended data types here. Needed for linking
template class List<int>;
