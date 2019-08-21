
class SLL:
    """A singly linked list. """

    class Node:
        """A node that holds data and pointer to the next node in a list."""
        def __init__(self, data=None, next=None):
            self.data = data
            self.next = next


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

        node.next = self.head
        self.head = node

        self.size += 1


    def search(self, target):
        """Searches list for a node containing the target data and returns it
        if found, otherwise returns None."""
        tmp = self.head

        while tmp != None:
            if tmp.data == target:
                return tmp
            tmp = tmp.next

        return tmp


    def print_list(self):
        """Prints the data of all the nodes in the list."""
        tmp = self.head

        while tmp != None:
            print(tmp.data, end=" ")
            tmp = tmp.next

        # print newline
        print("")
