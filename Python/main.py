"""
Test cases for my singly linked list implementation.
"""

from singly_linked_list import SLL

def create_int_list(list_size):
    """Creates and returns a simple list of n integers."""
    int_list = SLL()

    # add ints to list
    for i in range(1, list_size + 1):
        int_list.push(i)

    return int_list


def test_push():
    """Tests the push function."""
    list_size = 10
    mylist = create_int_list(list_size)
    mylist.print_list()

    assert mylist.get_size() == list_size


def test_search():
    """Test the search function."""
    list_size = 5
    mylist = create_int_list(list_size)

    assert mylist.get_size() == list_size
    assert mylist.search(4) != None
    assert mylist.search("hello") is None


def test_all():
    """Runs all test scripts."""
    test_push()
    test_search()


if __name__ == "__main__":
    test_all()
