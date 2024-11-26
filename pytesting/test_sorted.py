import pysort
import pytest

def test_sorted():
    A = [9., 1.2, 2., 3., 4.]
    B = pysort.sort_array(A)
    assert B == sorted(A)

def test_raise_type_error():
     with pytest.raises(TypeError):
          pysort.sort_array([1, '3', 1, '2'])