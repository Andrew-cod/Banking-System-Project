#include "solution.c"
#include <stdio.h>

#define CUSTOM_ASSERT(condition, message) \
    do { \
        if (!(condition)) { \
            fprintf(stderr, "Assertion failed: %s\n", message); \
        } \
    } while (0)

int main()
{
    const int size1 = 5;
    int test_binary_1[size1] = {1,2,3,4,5};
    int test_target_11 = 3;
    int test_target_12 = 9;

    const int size2 = 7;
    int test_binary_2[size2] = {1,3,6,10,50,70};
    int test_target_21 = 10;
    int test_target_22 = 68;

    CUSTOM_ASSERT(binarySearch(test_binary_1, size1, test_target_11) == 2, "TEST1");
    CUSTOM_ASSERT(binarySearch(test_binary_1, size1, test_target_12) == -1, "TEST2");

    CUSTOM_ASSERT(binarySearch(test_binary_2, size2, test_target_21) == 3, "TEST3");
    CUSTOM_ASSERT(binarySearch(test_binary_2, size2, test_target_22) == -1, "TEST4");

    const int size_range_1 = 10;
    int test_range_1[size_range_1] = {1,3,6,10,10,10,10,40,50,70};
    int index_left = -2;
    int index_right = -2;

    searchRange(test_range_1, size_range_1, 10, &index_left, &index_right);
    CUSTOM_ASSERT(index_left == 3, "TEST5");
    CUSTOM_ASSERT(index_right == 6, "TEST6");

    searchRange(test_range_1, size_range_1, 39, &index_left, &index_right);
    CUSTOM_ASSERT(index_left == -1, "TEST7");
    CUSTOM_ASSERT(index_right == -1, "TEST8");
    return 0;
}