#include "src/cppmult.hpp"

#include <cstdlib>
#include <iostream>

int main() {
  

  std::cout << cppmult(3, 4.5f);
  int arr[] = {4,5,6,7,2234,33};
  sorting(arr, 6);

  std::vector<double> input = {3.0, 5.0, 1.0};
  std::vector<double> out = modify(input);

  for (double i: out)
    std::cout << i << ' ';

}