#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                (long long)numbers[first] * numbers[second]);
        }
    }

    return max_product;
}


long long MaxPairwiseProductFast(const vector<int>& numbers) {
    int max1index = 0, max2index = 0, length = numbers.size(), max_temp = -1;

    for (int i = 0; i < length; ++i) {
        if (numbers[i] > max_temp) {
            max_temp = numbers[i];
            max1index = i;
        }
    }

    max_temp = -1;
    for (int i = 0; i < length; ++i) {
        if ((numbers[i] > max_temp) && (i != max1index)) {
            max_temp = numbers[i];
            max2index = i;
        }
    }

    return (long long)numbers[max1index] * numbers[max2index];
}


int main(void)
{
    while (true) {
        int n = rand() % 1000 + 2;
        vector<int> nums;

        for (int i = 0; i < n; ++i) {
            nums.push_back(rand() % 100000);
        }

        cout<< n << '\n';
        for (int i = 0; i < n; ++i) {
            cout<< nums[i] << ' ';
        }
        cout<< '\n';

        long long result1 = MaxPairwiseProduct(nums),
                  result2 = MaxPairwiseProductFast(nums);

        if (result1 != result2) {
            cout << "Wrong Answer: " << result1 << ", " << result2 << '\n';
            break;
        }

        else {
            cout<<"OK\n";
        }

    }

    // int n = 0;
    // cin>>n;

    // vector<int> a(n);

    // for (int i = 0; i < n; ++i) {
    //     cin>>a[i];
    // }

    // long long result = MaxPairwiseProductFast(a);
    // cout<< result << '\n';
    return 0;
}
