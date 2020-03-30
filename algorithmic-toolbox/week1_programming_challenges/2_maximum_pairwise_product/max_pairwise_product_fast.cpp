#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;


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

    int n = 0;
    cin>>n;

    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }

    long long result = MaxPairwiseProductFast(a);
    cout<< result << '\n';
    return 0;
}
