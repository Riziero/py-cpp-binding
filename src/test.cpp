#include "src/cppmult.hpp"
#include "gtest/gtest.h"

#include <vector>


TEST(TestSortingLib, BasicAssertions) {

    // FAIL(); 
    std::vector<double> input = {3., 2., 7.};
    std::vector<double> out = sort_array(input);
    EXPECT_TRUE(out[0] <= out[1]);

    for (int i = 0; i < out.size()-1; i++) { 
        EXPECT_TRUE(out[i] <= out[i+1]);
    }
}


int main(int nArgs, char** vArgs) {
    ::testing::InitGoogleTest(&nArgs, vArgs);
    return RUN_ALL_TESTS();
}
