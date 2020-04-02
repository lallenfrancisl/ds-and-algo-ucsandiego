#include <iostream>
#include <vector>

using namespace std;

// Global variables go here
vector<unsigned int> fibonacci_last_digits;
// Pisano period of 10 is 60
const int PISANO_PERIOD = 60;

// Finds the sum of the last digits of a fibonacci sequence till n using the naive way
unsigned long long fibonacci_sum_naive(unsigned long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;
    long long sum = 1;

    for (unsigned long long i = 0; i < n - 1; ++i) {
        unsigned long long tmp_previous = previous % 10;
        previous = current % 10;
        current = (tmp_previous + current) % 10;
        sum += current;
    }

    return sum % 10;
}


vector<unsigned int> generate_fibonacci_sequence(unsigned long long n) {
    vector<unsigned int> fibonacci_last_digits;
    fibonacci_last_digits.push_back(0), fibonacci_last_digits.push_back(1);

    for (unsigned int i = 2; i <= PISANO_PERIOD; ++i) {
        // generate the fibonacci sequence (mod 10)
        fibonacci_last_digits.push_back((fibonacci_last_digits[i - 1] + fibonacci_last_digits[i - 2]) % 10);
    }

    return fibonacci_last_digits;
}


// Finds the sum of the last digits of a fibonacci sequence till n using the naive way
unsigned int fibonacci_sum_fast(unsigned long long n) {
    unsigned long long sum = 0, remainder = n % PISANO_PERIOD;

    fibonacci_last_digits = generate_fibonacci_sequence(PISANO_PERIOD);

    // find the sum of fibonacci last digits
    for (unsigned int i = 0; i <= remainder; ++i) {
        sum += fibonacci_last_digits[i];
        sum %= 10;
    }

    return sum;
}


void test_solution() {
    unsigned long long naive, fast;

    for (int m = 1; m < 10000000; ++m) {
        naive = fibonacci_sum_naive(m);
        fast = fibonacci_sum_fast(m);
        cout << "Naive: " << naive;
        cout << "Fast: " << fast << '\n';

        if (fast != naive) {
            cout << "Error!!!\n";
            exit(1);
        }
    }
}


int main() {
    unsigned long long n = 0;
    cin >> n;
    // cout << "Naive: " << fibonacci_sum_naive(n) << "\n";
    cout << fibonacci_sum_fast(n) << "\n";
    // test_solution();
    return 0;
}
