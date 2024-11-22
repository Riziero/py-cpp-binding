#include <vector>
#define EXPORT_SYMBOL

extern "C" {
    EXPORT_SYMBOL float cppmult(int int_param, float float_param);
    EXPORT_SYMBOL void sorting(int* arr, int size);
    EXPORT_SYMBOL std::vector<double> sort_array(const std::vector<double>& input);
}

