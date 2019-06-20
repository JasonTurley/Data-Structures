#include <iostream>

#include "list.h"

using namespace std;

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
void List<T>::print() const
{
        ListNode *temp = head;

        while (temp) {
                cout << temp->data << " ";
                temp = temp->next;
        }

        cout << endl;
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
                        // TODO traverse from tail if index is closer to the end
                        // of the list!
                        ListNode *ptr = head;

                        for (size_t i = 0; i < index-1; i++)
                                ptr = ptr->next;

                        temp->next = ptr->next;
                        ptr->next = temp;
                        temp->prev = ptr;

                        if (temp->next)
                                temp->next->prev = temp;
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
        ListNode *ptr = NULL;
        T retval = T();

        if (empty())
                return retval;

        // Remove from head
        if (index == 0) {
                ptr = head;

                // Are we removing the last node?
                if (head == tail)
                        head = tail = nullptr;
                else
                        head = head->next;

        // Remove from tail
        } else if (index >= length - 1) {
                ptr = tail;

                // Are we removing the last node?
                if (head == tail)
                        head = tail = nullptr;
                else
                        tail = tail->prev;

        // Remove from index
        } else {
                // TODO: traverse from tail if index is closer to the end of the
                // list
                ptr = head;

                for (size_t i = 0; i < index; i++)
                        ptr = ptr->next;

                // Unlink the target node
                ptr->prev->next = ptr->next;
                ptr->next->prev = ptr->prev;
        }

        retval = ptr->data;
        free(ptr);
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

// Declare intended data types here. Needed for linking
template class List<int>;
