#!/usr/bin/python
# -*- coding: utf-8 -*-

"""Unit tests for my Stack implementation.

Todo:
    * Add unit test for pop, peek and get_size

"""
import stack

def test_push():
    """Unit test for stack.push() method
    """
    mystack = stack.Stack()

    for i in range(16):
        mystack.push(i)

    mystack.print_stack()
    assert mystack.get_size() == 16


def test_all():
    """Runs all unit tests.
    """
    test_push()


if __name__ == "__main__":
    test_all()
