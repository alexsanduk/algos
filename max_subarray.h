#ifndef MAX_SUBARRAY_H_
#define MAX_SUBARRAY_H_
class MaxSubArray {
public: 
    MaxSubArray(int * a, int size, int method) {
        if (method == 0) {
            set_max_subarray_brute(a, size);
        }
        else if (method == 1) {
            set_max_subarray_linear(a, size);
        }
        else {
            max_subarray_ = set_max_subarray_divide(a, 0, size - 1);
        }
    }
    int sum() const {
        return max_subarray_.sum;
    }
    int left() const {
        return max_subarray_.left;
    }
    int right() const {
        return max_subarray_.right;
    }
private:
    struct SubArray {
        int left;
        int right;
        int sum;
    };
    SubArray max_subarray_;
    void set_max_subarray_brute(int * a, int size);
    void set_max_subarray_linear(int * a, int size);
    SubArray set_max_subarray_divide(int * a, int i, int j);
    SubArray set_max_subarray_conquer(int * a, int i, int m, int j);
};
#endif
