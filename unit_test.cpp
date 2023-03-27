#include "Compression.hpp"
#include <gtest/gtest.h>

TEST(CalculateEntropyTest, EmptyData) {
    vector<unsigned char> data;
    vector<double> entropy = Compression::calculate_entropy(data);
    EXPECT_EQ(entropy.size(), 3);
    EXPECT_DOUBLE_EQ(entropy[0], 0);
    EXPECT_DOUBLE_EQ(entropy[1], 0);
    EXPECT_DOUBLE_EQ(entropy[2], 0);
}

TEST(CalculateEntropyTest, SingleByteData) {
    vector<unsigned char> data = {0xFF};
    vector<double> entropy = Compression::calculate_entropy(data);
    EXPECT_EQ(entropy.size(), 3);
    EXPECT_DOUBLE_EQ(entropy[0], 0);
    EXPECT_DOUBLE_EQ(entropy[1], 0);
    EXPECT_DOUBLE_EQ(entropy[2], 0);
}

TEST(CalculateEntropyTest, MultiByteData) {
    vector<unsigned char> data = {0xFF, 0x00, 0x55, 0xAA, 0xFF};
    vector<double> entropy = Compression::calculate_entropy(data);
    EXPECT_EQ(entropy.size(), 3);
    EXPECT_DOUBLE_EQ(entropy[0], 1.5219280948873621);
    EXPECT_DOUBLE_EQ(entropy[1], 8);
    EXPECT_DOUBLE_EQ(entropy[2], 0);
}

// Add more tests as needed

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
