class Stack:
    def __init__(self):
        self.container = []
        self.size = 0

    def push(self, elem):
        """Adds an element to the top of the stack, effectively increasing its
        size by one."""
        self.container.append(elem)
        self.size += 1

    def pop(self):
        """Removes and returns the element at the top of the stack, effectively
        decreasing its size by one."""
        try:
            elem = self.container[self.size]
            self.size -= 1
            return elem

        except IndexError:
            print("Stack is empty.")

    def peek(self):
        """Returns the element at the top of the stack without removing it."""
        try:
            return self.container[self.size]
        except IndexError:
            print("Stack is empty.")

    def get_size(self):
        """Returns the current number of elements in the stack."""
        return self.size

    def print_stack(self):
        """Prints the contents of the stack without modifying it."""
        pos = self.size - 1
        print("Stack: ", end="")

        while pos >= 0:
            print(self.container[pos], end=" ")
            pos -= 1
        print("")
