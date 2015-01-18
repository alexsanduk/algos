#include "max_subarray.h"
#include <gtest/gtest.h>
TEST(MaxSubArrayTest, HandlesArrayWithOnePositiveElement) {
    int current_array[] = {1};
    int n = sizeof(current_array) / sizeof(current_array[0]);
    int expected_left = 0;
    int expected_right = 0;
    int expected_sum = 1;
    // brute
    MaxSubArray max(current_array, n, 0);
    EXPECT_EQ(expected_left, max.left());
    EXPECT_EQ(expected_right, max.right());
    EXPECT_EQ(expected_sum, max.sum());
    // linear
    max = MaxSubArray(current_array, n, 1);
    EXPECT_EQ(expected_left, max.left());
    EXPECT_EQ(expected_right, max.right());
    EXPECT_EQ(expected_sum, max.sum());
    // divide and conquer
    max = MaxSubArray(current_array, n, 2);
    EXPECT_EQ(expected_left, max.left());
    EXPECT_EQ(expected_right, max.right());
    EXPECT_EQ(expected_sum, max.sum());
}
TEST(MaxSubArrayTest, HandlesArrayWithOneNegativeElement) {
    int current_array[] = {-1};
    int n = sizeof(current_array) / sizeof(current_array[0]);
    int expected_left = 0;
    int expected_right = 0;
    int expected_sum = -1;
    // brute
    MaxSubArray max(current_array, n, 0);
    EXPECT_EQ(expected_left, max.left());
    EXPECT_EQ(expected_right, max.right());
    EXPECT_EQ(expected_sum, max.sum());
    // linear
    max = MaxSubArray(current_array, n, 1);
    EXPECT_EQ(expected_left, max.left());
    EXPECT_EQ(expected_right, max.right());
    EXPECT_EQ(expected_sum, max.sum());
    // divide and conquer
    max = MaxSubArray(current_array, n, 2);
    EXPECT_EQ(expected_left, max.left());
    EXPECT_EQ(expected_right, max.right());
    EXPECT_EQ(expected_sum, max.sum());
}
TEST(MaxSubArrayTest, HandlesArrayWithOnlyPositiveElements) {
    int current_array[] = {3, 2, 1, 4, 5, 6};
    int n = sizeof(current_array) / sizeof(current_array[0]);
    int expected_left = 0;
    int expected_right = 5;
    int expected_sum = 21;
    // brute
    MaxSubArray max(current_array, n, 0);
    EXPECT_EQ(expected_left, max.left());
    EXPECT_EQ(expected_right, max.right());
    EXPECT_EQ(expected_sum, max.sum());
    // linear
    max = MaxSubArray(current_array, n, 1);
    EXPECT_EQ(expected_left, max.left());
    EXPECT_EQ(expected_right, max.right());
    EXPECT_EQ(expected_sum, max.sum());
    // divide and conquer
    max = MaxSubArray(current_array, n, 2);
    EXPECT_EQ(expected_left, max.left());
    EXPECT_EQ(expected_right, max.right());
    EXPECT_EQ(expected_sum, max.sum());
}

TEST(MaxSubArrayTest, HandlesArrayWithOnlyNegativeElements) {
    int current_array[] = {-3, -5, -1, -2};
    int n = sizeof(current_array) / sizeof(current_array[0]);
    int expected_left = 2;
    int expected_right = 2;
    int expected_sum = -1;
    // brute
    MaxSubArray max(current_array, n, 0);
    EXPECT_EQ(expected_left, max.left());
    EXPECT_EQ(expected_right, max.right());
    EXPECT_EQ(expected_sum, max.sum());
    // linear
    max = MaxSubArray(current_array, n, 1);
    EXPECT_EQ(expected_left, max.left());
    EXPECT_EQ(expected_right, max.right());
    EXPECT_EQ(expected_sum, max.sum());
    // divide and conquer
    max = MaxSubArray(current_array, n, 2);
    EXPECT_EQ(expected_left, max.left());
    EXPECT_EQ(expected_right, max.right());
    EXPECT_EQ(expected_sum, max.sum());
}
TEST(MaxSubArrayTest, HandlesArrayWithMixedElements) {
    int current_array[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(current_array) / sizeof(current_array[0]);
    int expected_left = 3;
    int expected_right = 6;
    int expected_sum = 6;
    // brute
    MaxSubArray max(current_array, n, 0);
    EXPECT_EQ(expected_left, max.left());
    EXPECT_EQ(expected_right, max.right());
    EXPECT_EQ(expected_sum, max.sum());
    // linear
    max = MaxSubArray(current_array, n, 1);
    EXPECT_EQ(expected_left, max.left());
    EXPECT_EQ(expected_right, max.right());
    EXPECT_EQ(expected_sum, max.sum());
    // divide and conquer
    max = MaxSubArray(current_array, n, 2);
    EXPECT_EQ(expected_left, max.left());
    EXPECT_EQ(expected_right, max.right());
    EXPECT_EQ(expected_sum, max.sum());
}
int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
