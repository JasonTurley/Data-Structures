"""An implementation of a singly linked list.
"""

class SLL(object):
    """A list of connected nodes.
    """

    class Node(object):
        """A node within the linked list.

        Args:
            data (object): The data to insert to the list
        """
        def __init__(self, data=None):
            self.data = data
            self.next_node = None

        def get_data(self):
            """Returns the data within a node.

            Return:
                The data within a node.
            """
            return self.data

        def set_next(self, node):
            """Sets the current node's next field to point to the given node.
            """
            self.next_node = node

    def __init__(self):
        self.head = None
        self.size = 0

    def get_size(self):
        """Returns the current number of nodes in the list.

        Return:
            The current number of nodes in the list.
        """
        return self.size

    def push(self, data):
        """Inserts a node at the front of the list, effectively increasing its
        size by one.

        Args:
            data (object): The data to add to the list.
        """
        node = self.Node(data)

        node.set_next(self.head)
        self.head = node

        self.size += 1

    def search(self, target):
        """Searches the list for the node containing the target data.

        Return:
            Data within a node or None if the node is not found.
        """
        tmp = self.head

        while tmp != None:
            if tmp.get_data() == target:
                return tmp
            tmp = tmp.next_node

        return tmp

    def print_list(self):
        """Prints the data of all the nodes in the list.
        """
        tmp = self.head

        while tmp != None:
            print(tmp.data, end=" ")
            tmp = tmp.next_node

        print("")
