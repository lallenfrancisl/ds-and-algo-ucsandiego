#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

long long binary_search(const vector<long long> &a, int find) {
    long long left = 0, right = (long long)a.size() - 1, mid = 0;
    // binary search loop
    while(left <= right) {
        mid = left + (right - left) / 2;

        if(a[mid] == find) {
            // the element is found, return its index
            return mid;
        }
        else if(find > a[mid]) {
             left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    // the element is not found return -1
    return -1;
}

int linear_search(const vector<int> &a, int x) {
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] == x)
            return i;
    }
    return -1;
}

int main() {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        cin >> a[i];
    }
    long long m;
    cin >> m;
    vector<long long> b(m);
    for (long long i = 0; i < m; ++i) {
        cin >> b[i];
    }
    for (long long i = 0; i < m; ++i) {
        cout << binary_search(a, b[i]) << ' ';
    }
}
