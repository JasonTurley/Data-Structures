from singly_linked_list import SLL

def create_int_list(n):
    """Creates and returns a simple list of n integers."""
    int_list = SLL()

    # add ints to list
    for i in range(1, n+1):
        int_list.push(i)

    return int_list


def test_push():
    """Tests the push function."""
    n = 10
    mylist = create_int_list(n)
    mylist.print_list()

    assert mylist.get_size() == n


def test_search():
    """Test the search function."""
    n = 5
    mylist = create_int_list(n)

    assert mylist.get_size() == n
    assert mylist.search(4) != None
    assert mylist.search("hello") == None


def test_all():
    """Runs all test scripts."""
    test_push()
    test_search()


if __name__ == "__main__":
    """Driver program."""
    test_all()
