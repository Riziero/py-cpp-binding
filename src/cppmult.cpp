#include <iostream>
#include <iomanip>
#include <algorithm>
#include "cppmult.hpp"

#include <bits/stdc++.h>

// #include <pybind11/pybind11.h>
// #include <pybind11/stl.h>
#include <vector>

using namespace std;


float cppmult(int int_param, float float_param) {
    float return_value = int_param * float_param;
    std::cout << std::setprecision(1) << std::fixed
	          << "    In cppmul: int " << int_param
	          << " float " <<  float_param
	          << " returning  " << return_value
	          << std::endl;
    return return_value;
}

void sorting(int* array_param, int size_param){

	// int* toRet = new int[size_param];
	// std::cout<<"toRet size: "<<sizeof(toRet);
	for(int i=0; i<size_param; i++)
    {
        for(int j=i+1; j<size_param; j++) { 
			if(array_param[i]>array_param[j]){
                int temp = array_param[i];
                array_param[i] = array_param[j];
                array_param[j] = temp;
            }
        }
	}

	std::cout<<"After swapping"<<std::endl;


	for(int i=0; i<size_param; i++)
		cout<<int(array_param[i])<<" ";

	std::cout<<std::endl;

}

std::vector<double> sort_array(const std::vector<double>& input)
{
   std::vector<double> sortedVec = input;
    
    // Sort the vector in ascending order
    std::sort(sortedVec.begin(), sortedVec.end());
    
    // Return the sorted vector
    return sortedVec;
}