#include <limits>
#include "max_subarray.h"
void MaxSubArray::set_max_subarray_brute(int * a, int size) {
    int max_sum = std::numeric_limits<int>::min();
    int sum;
    int left_index;
    int right_index;
    for (int i = 0; i < size; ++i) {
        sum = 0;
        for (int j = i; j < size; ++j) {
            sum += a[j];
            if (sum > max_sum) {
                max_sum = sum;
                left_index = i;
                right_index = j;
            }
        }
    }
    max_subarray_.left = left_index;
    max_subarray_.right = right_index;
    max_subarray_.sum = max_sum;
}
void MaxSubArray::set_max_subarray_linear(int * a, int size) {
    // min sum from 0 to i
    // initially it is 0 since no elements are included
    int min_so_far = 0;
    // index for which we have min sum described above
    int index_min_so_far = -1;
    int max_sum = std::numeric_limits<int>::min();
    // running sum from 0 to i
    int sum = 0;
    int left_index;
    int right_index;
    for (int i = 0; i < size; ++i)
    {
        sum += a[i];
        if (sum - min_so_far >= max_sum) {
            max_sum = sum - min_so_far;
            left_index = index_min_so_far;
            right_index = i;
        }
        if (sum <= min_so_far) {
            min_so_far = sum;
            index_min_so_far = i;
        }
    }
    max_subarray_.left = left_index + 1;
    max_subarray_.right = right_index;
    max_subarray_.sum = max_sum;
}
// computing max subarray via divide and conquer method
MaxSubArray::SubArray MaxSubArray::set_max_subarray_divide(int * a, int i, int j) {
    if (i < j) {
        int m = (i + j) / 2;
        SubArray left_max_subarray = MaxSubArray::set_max_subarray_divide(a, i, m - 1);
        SubArray mid_max_subarray = MaxSubArray::set_max_subarray_conquer(a, i, m, j);
        SubArray right_max_subarray = MaxSubArray::set_max_subarray_divide(a, m + 1, j);
        if (left_max_subarray.sum >= mid_max_subarray.sum &&
            left_max_subarray.sum >= right_max_subarray.sum) {
            return left_max_subarray;
        }
        else if (right_max_subarray.sum >= mid_max_subarray.sum &&
                 right_max_subarray.sum >= left_max_subarray.sum) {
            return right_max_subarray;;
        }
        else {
            return mid_max_subarray;
        }
    }
    else if (i == j) {
        SubArray one_element_subarray = {i, i, a[i]};
        return one_element_subarray;
    }
    else {
        SubArray empty_subarray = {-1, -1, std::numeric_limits<int>::min()};
        return empty_subarray;
    }
}
MaxSubArray::SubArray MaxSubArray::set_max_subarray_conquer(int * a, int i, int m, int j) {
    int max_left = 0;
    int max_left_index = m;
    int max_right = 0;
    int max_right_index = m;
    // starting
    int sum = 0;
    for (int k = m - 1; k >= i; --k)
    {
        sum += a[k];
        if (sum >= max_left) {
            max_left = sum;
            max_left_index = k;
        }
    }
    sum = 0;
    for (int k = m + 1; k <= j; ++k)
    {
        sum += a[k];
        if (sum >= max_right) {
            max_right = sum;
            max_right_index = k;
        }
    }
    SubArray result = {max_left_index, max_right_index, max_left + a[m] + max_right};
    return result;
}
