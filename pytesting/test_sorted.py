import pysort
import pytest

def test_sorted():
    A = [9., 1.2, 2., 3., 4.]

    B = pysort.sort_array(A)
    if sorted(A) != B:
        # Make it fail
        assert True==False