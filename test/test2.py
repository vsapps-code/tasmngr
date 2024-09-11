from ctypes import CDLL

import pytest


@pytest.fixture
def libfact():
    yield CDLL("../fact.so")


@pytest.mark.parametrize("n,e", [(6, 720), (0, 1), (-42, 1)])
def test_fact(libfact, n, e):
    """! Maps a number from one range to another.
    @param libfact  The input number to map.
    @param n        The minimum value of an input number.
    @param e        The maximum value of an input number.
    @param out_min  The minimum value of an output number.
    @param out_max  The maximum value of an output number.
    @par Requirements Traceability
        - @ref SRS_EXA_BOOT_01
    @par Test Traceability
        - @ref STS_BOOT_00
    @return  The mapped number.
    """
    assert libfact.fact(n) == e
