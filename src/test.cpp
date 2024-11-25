/**
 * tests/test_defaults.cpp
 */

#include "src/cppmult.hpp"
#include "gtest/gtest.h"

#include <vector>


TEST(TestDefaults, BasicAssertions) {

    
    // Vector<double> input = {3., 2. 7.};
    // Vector<double> out = sort_array(input);

    // for (int i = 0; i < out.length(); i++) { 
        
    //     if (out[i] > out[i + 1]) {
    //         FAIL();    
    //     }
    // }

    // EXPECT_STREQ(p.name.c_str(), "unknown");
    // EXPECT_EQ(p.age, 0);
}


int main(int nArgs, char** vArgs) {
    ::testing::InitGoogleTest(&nArgs, vArgs);
    return RUN_ALL_TESTS();
}
