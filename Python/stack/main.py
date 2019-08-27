#!/usr/bin/python

import stack

def test_push():
    s = stack.Stack()

    for i in range(16):
        s.push(i)

    s.print_stack()
    assert s.get_size() == 16


def test_all():
    test_push()


if __name__ == "__main__":
    test_all()
