#include <iostream>
#include <vector>
#include <cstdlib>
#include <cassert>
#include <ctime>

using namespace std;

/**
 * Print vectors in a line incase needed for utility
 */
void print_vec(vector<long long> &vec, size_t begin, size_t end) {
    for (size_t i = begin; i < end; ++i)
        cout << vec[i] << " ";

    cout << endl;
}


/**
 * Merge function for merge sort algorithm
 */
int merge(vector<long long> &sorted_nums, size_t left, size_t ave,
                size_t right) {
    long long left_len = ave - left, right_len = right - ave;
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

    return 0;
}


/**
 * Merge sort function
 */
int merge_sort(vector<long long> &a, size_t left,
                                   size_t right) {
    if (right <= left + 1) {
        return 0;
    }

    size_t ave = (left + right) / 2;
    merge_sort(a, left, ave);
    merge_sort(a, ave, right);

    merge(a, left, ave, right);

    return 0;
}


/**
 * find the smallest element which is above find
 */
long long modif_binary_search(const vector<long long> &a, int find) {
    long long left = 0, right = (long long)a.size() - 1, mid = 0;

    // binary search loop
    while(left <= right) {
        mid = left + (right - left) / 2;

        if(find >= a[mid]) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return left;
}


vector<long long> fast_count_segments(vector<long long> &starts,
                                      vector<long long> &ends,
                                      vector<long long> &points) {
    vector<long long> cnt(points.size());
    long long seg_cnt = starts.size(), points_cnt = points.size();

    // sort the segments in increasing order
    merge_sort(starts, 0, seg_cnt);
    merge_sort(ends, 0, seg_cnt);

    // scan through the segments and check if points are in the
    // in the segments
    for (long long i = 0; i < points_cnt; ++i) {
        if (seg_cnt <= 1)
        {
            cnt[i] = (long long)((points[i] >= starts[0]) && (points[i] <= ends[0]));
        }
        else {
            cnt[i] = modif_binary_search(starts, points[i]);
            cnt[i] -= modif_binary_search(ends, points[i] - 1);
        }
    }

    return cnt;
}

vector<long long> naive_count_segments(vector<long long> starts,
                                       vector<long long> ends,
                                       vector<long long> points) {
    vector<long long> cnt(points.size());
    for (size_t i = 0; i < points.size(); i++) {
        for (size_t j = 0; j < starts.size(); j++) {
            cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
        }
    }
    return cnt;
}


/**
 * Compare function for using in stress test
 */
bool compare(vector<long long> v1, vector<long long> v2) {
    long long leng = v1.size();
    for (long long i = 0; i < leng; ++i) {
        if (v1[i] != v2[i])
            return true;
    }

    return false;
}


/**
 * Stress test function
 */
void stress_test() {
    vector<long long> cnt1, cnt2;
    while (true) {
        // make the starts array
        long long limit = 100, leng = rand() % 6 + 1;
        vector<long long> starts(leng);
        for (long long i = 0; i < leng; ++i) {
            starts[i] = rand() % 100;
        }

        // make the ends array
        vector<long long> ends(leng);
        for (long long i = 0; i < leng; ++i) {
            ends[i] = starts[i] + rand() % limit;
        }

        // make points array
        long long point_limit = rand() % 10 + 1;
        vector<long long> points(point_limit);
        for (long long i = 0; i < point_limit; ++i) {
            points[i] = rand() % 200;
        }


        cnt1 = fast_count_segments(starts, ends, points);
        cnt2 = naive_count_segments(starts, ends, points);
        if (compare(cnt1, cnt2)) {
            cout << "starts: "; print_vec(starts, 0, starts.size());
            cout << "ends: "; print_vec(ends, 0, ends.size());
            cout << "points: "; print_vec(points, 0, points.size());
            cout << "fast: "; print_vec(cnt1, 0, cnt1.size());
            cout << "naive: "; print_vec(cnt2, 0, cnt2.size());
            break;
        }
    }
}

int main() {
    // uncomment next line to do stress test
    // stress_test();
    long long n, m;
    cin >> n >> m;
    vector<long long> starts(n), ends(n);
    for (size_t i = 0; i < starts.size(); i++) {
        cin >> starts[i] >> ends[i];
    }

    vector<long long> points(m);
    for (size_t i = 0; i < points.size(); i++) {
        cin >> points[i];
    }

    // use fast_count_segments
    vector<long long> cnt = fast_count_segments(starts, ends, points);
    for (size_t i = 0; i < cnt.size(); i++) {
        cout << cnt[i] << ' ';
    }

    return 0;
}
