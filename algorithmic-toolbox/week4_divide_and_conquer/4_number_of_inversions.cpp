#include <iostream>
#include <vector>

using namespace std;


void print_vec(vector<long long> &vec, size_t begin, size_t end) {
    for (size_t i = begin; i < end; ++i)
        cout << vec[i] << " ";

    cout << endl;
}

/**
 * Merge function for merge sort algorithm
 */
long long merge(vector<long long> &sorted_nums, size_t left, size_t ave,
                size_t right) {
    long long left_len = ave - left, right_len = right - ave, number_of_inversions = 0;
    vector<long long> left_els(left_len), right_els(right_len);

    // make left copy
    for (long long i = 0; i < left_len; ++i) {
        left_els[i] = sorted_nums[left + i];
    }
    // make right copy
    for (long long i = 0; i < right_len; ++i)
    {
        right_els[i] = sorted_nums[ave + i];
    }

    // merge them to the sorted array
    long long left_index = 0, right_index = 0, sorted_index = left;
    while((left_index < left_len) && (right_index < right_len)) {
        if (left_els[left_index] <= right_els[right_index])
        {
            sorted_nums[sorted_index] = left_els[left_index];
            ++left_index;
        }
        else {
            sorted_nums[sorted_index] = right_els[right_index];
            ++right_index;
            number_of_inversions += left_len - left_index;
        }

        ++sorted_index;
    }

    // copy the rest from left element arrays if any
    while (left_index < left_len)
    {
        sorted_nums[sorted_index] = left_els[left_index];
        ++left_index;
        ++sorted_index;
    }

    // copy the rest from right half array if any
    while (right_index < right_len)
    {
        sorted_nums[sorted_index] = right_els[right_index];
        ++right_index;
        ++sorted_index;
    }

    return number_of_inversions;
}

/**
 * Merge sort function
 */
long long get_number_of_inversions(vector<long long> &a, vector<long long> &b, size_t left,
                                   size_t right) {
    long long number_of_inversions = 0;
    if (right <= left + 1) {
        // Just assigning since it does not matter which is larger since
        // we are going to merge it anyway on returning
        b[left] = a[left];
        b[right - 1] = a[right - 1];
        return number_of_inversions;
    }

    size_t ave = (left + right) / 2;number_of_inversions += get_number_of_inversions(a, b, left, ave);
    number_of_inversions += get_number_of_inversions(a, b, ave, right);

    number_of_inversions += merge(b, left, ave, right);

    return number_of_inversions;
}

int main() {
    long long n;
    cin >> n;
    vector<long long> nums(n);
    for (size_t i = 0; i < nums.size(); i++) {
        cin >> nums[i];
    }
    vector<long long> sorted_nums(nums.size());
    cout << get_number_of_inversions(nums, sorted_nums, 0, nums.size()) << '\n';

    return 0;
}
