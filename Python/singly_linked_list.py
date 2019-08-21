"""
An implementation of a singly linked list in python3.
"""

class SLL(object):
    """A singly linked list. """

    class Node(object):
        """A node that holds data and pointer to the next_node node in a list."""
        def __init__(self, data=None, next_node=None):
            self.data = data
            self.next_node = next_node


        def get_data(self):
            """Returns a node's data."""
            return self.data


        def set_next(self, node):
            """Sets the current node's next field to point to the given node."""
            self.next_node = node


    def __init__(self, head=None, size=0):
        self.head = head
        self.size = size


    def get_size(self):
        """Returns the current number of nodes in the list."""
        return self.size


    def push(self, data):
        """Inserts a node at the front of the list, effectively increasing its
        size by one."""
        node = self.Node(data)

        node.set_next(self.head)
        self.head = node

        self.size += 1


    def search(self, target):
        """Searches list for a node containing the target data and returns it
        if found, otherwise returns None."""
        tmp = self.head

        while tmp != None:
            if tmp.get_data() == target:
                return tmp
            tmp = tmp.next_node

        return tmp


    def print_list(self):
        """Prints the data of all the nodes in the list."""
        tmp = self.head

        while tmp != None:
            print(tmp.data, end=" ")
            tmp = tmp.next_node

        # print newline
        print("")
