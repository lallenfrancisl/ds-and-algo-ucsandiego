#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int get_majority_element(vector<long long> &nums, long long left,
                         long long right) {
    if (left == right)
        return nums[left];
    if (left + 1 == right)
        return nums[left];

    long long left_maj = -1, right_maj = -1, left_maj_cnt = 0,
              right_maj_cnt = 0;

    left_maj = get_majority_element(nums, left, (left + right - 1) / 2);
    right_maj = get_majority_element(nums, (left + right - 1) / 2 + 1, right);

    for (long long i = left; i < right; ++i) {
        if (nums[i] == left_maj) {
            left_maj_cnt += 1;
        }
        if (nums[i] == right_maj) {
            right_maj_cnt += 1;
        }

        if(left_maj_cnt > (right - left) / 2) {
            return left_maj;
        }
        if(right_maj_cnt > (right - left) / 2) {
            return right_maj;
        }
    }

    return -1;
}

int main() {
    long long n;
    cin >> n;
    vector<long long> nums(n);
    for (unsigned int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    cout << (get_majority_element(nums, 0, nums.size()) != -1) << '\n';

    return 0;
}
