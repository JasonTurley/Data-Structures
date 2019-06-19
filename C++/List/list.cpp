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
int List<T>::size() const
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
void List<T>::insertFront(const T& ndata)
{
        ListNode *temp = new ListNode(ndata);

        if (empty()) {
                head = tail = temp;
        } else {
                head->prev = temp;
                temp->next = head;
                head = temp;
        }

        length++;
}

template <class T>
void List<T>::insertBack(const T& ndata)
{
        ListNode *temp = new ListNode(ndata);

        if (empty()) {
                head = tail = temp;
        } else {
                tail->next = temp;
                temp->prev = tail;
                tail = temp;
        }

        length++;
}

template <class T>
const T List<T>::popFront()
{
        if (empty())
                return T();

        ListNode *temp = head;
        const T retval = head->data;

        head = head->next;
        temp->next = nullptr;

        // Set tail to NULL if this is the last node in the list
        if (!head)
                tail = nullptr;
        else
                head->prev = nullptr;

        delete temp;
        temp = nullptr;
        length--;

        return retval;
}

template <class T>
const T List<T>::popBack()
{
        if (empty())
                return T();

        ListNode *temp = tail;
        const T retval = tail->data;

        tail = tail->prev;
        temp->prev = nullptr;

        // Set head to NULL if this is the last node in the list
        if (!tail)
                head = nullptr;
        else
                tail->next = nullptr;

        delete temp;
        temp = nullptr;
        length--;

        return retval;
}

// Declare intended data types here. Needed for linking
template class List<int>;
