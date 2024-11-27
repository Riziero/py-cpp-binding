#include <iostream>
#include <algorithm>
#include "sortArray.hpp"
#include <vector>


std::vector<double> sort_array(const std::vector<double>& input)
{
   std::vector<double> sortedVec = input;
    
    // Sort the vector in ascending order
    std::sort(sortedVec.begin(), sortedVec.end());
    
    // Return the sorted vector
    return sortedVec;
}