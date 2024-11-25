#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <vector>
#define EXPORT_SYMBOL

extern "C" {
    EXPORT_SYMBOL float cppmult(int int_param, float float_param);
    EXPORT_SYMBOL void sorting(int* arr, int size);
    EXPORT_SYMBOL std::vector<double> sort_array(const std::vector<double>& input);
}

namespace py = pybind11;

PYBIND11_MODULE(pysort,m)
{
  m.doc() = "pybind11 example plugin";

  m.def("sort_array", &sort_array, "Multiply all entries of a list by 2.0");
}