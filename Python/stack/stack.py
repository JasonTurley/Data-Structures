# -*- coding: utf-8 -*-
"""Implementation of a stack using the built-in list data type.

Todo:
"""
class Stack(object):
    """Stack implementation.

    Attributes:
        container (list): The built-in list to hold stack elements.
        size (int): The current number of elements in the stack.
    """
    def __init__(self):
        self.container = []
        self.size = 0

    def push(self, elem):
        """Adds an element to the top of the stack, effectively increasing its
        size by one.

        Args:
            elem (object): The element to append to the stack.
        """
        self.container.append(elem)
        self.size += 1

    def pop(self):
        """Removes and returns the element at the top of the stack, effectively
        decreasing its size by one.

        Returns:
            The element at the top of the stack.

        Raises:
            IndexError: If index is outside stack bounds.
        """
        try:
            elem = self.container[self.size]
            self.size -= 1
            return elem

        except IndexError:
            print("Stack is empty.")

    def peek(self):
        """Returns the element at the top of the stack without removing it.

        Returns:
            The element at the top of the stack.

        Raises:
            IndexError: If index is outside stack bounds.

        """
        try:
            return self.container[self.size]
        except IndexError:
            print("Stack is empty.")

    def get_size(self):
        """Returns the current number of elements in the stack.

        Returns:
            The current number of elements in that stack.
        """
        return self.size

    def print_stack(self):
        """Prints the contents of the stack without modifying it.
        """
        pos = self.size - 1
        print("Stack: ", end="")

        while pos >= 0:
            print(self.container[pos], end=" ")
            pos -= 1
        print("")
