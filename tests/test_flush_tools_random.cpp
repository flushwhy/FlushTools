#include <gtest/gtest.h>
#include "FlushTools.hpp"

TEST(FlushToolsTest, RandomGenInRange) {
    FlushTools tool;
    
    unsigned long long min_val = 100;
    unsigned long long max_val = 1000;
    unsigned long long result = tool.randomGen(min_val, max_val);

    // Assert that the result is between min_val and max_val
    ASSERT_GE(result, min_val);
    ASSERT_LE(result, max_val);
}

// Test if randomGen behaves well with the full default range
TEST(FlushToolsTest, RandomGenInRangeFullDefault) { // Renamed test case
    FlushTools tool;
    for (int i = 0; i < 10000; ++i) {
        auto result = tool.randomGen(0, 100); // Adjust range as necessary
        ASSERT_GE(result, 0);
        ASSERT_LE(result, 100);
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

