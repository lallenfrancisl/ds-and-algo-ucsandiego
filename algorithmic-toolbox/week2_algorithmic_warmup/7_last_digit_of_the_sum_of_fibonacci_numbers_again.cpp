#include <iostream>
#include <vector>

using namespace std;

// Global variables go here
vector<unsigned int> fibonacci_last_digits;
// Pisano period of 10 is 60
const int PISANO_PERIOD = 60;


long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current % 10;
        }

        long long new_current = next;
        next = (next + current) % 10;
        current = (new_current) % 10;
    }

    return sum % 10;
}


vector<unsigned int> generate_fibonacci_sequence(unsigned long long n) {
    vector<unsigned int> fibonacci_last_digits;
    fibonacci_last_digits.push_back(0), fibonacci_last_digits.push_back(1);

    for (unsigned int i = 2; i <= PISANO_PERIOD; ++i) {
        // generate the fibonacci sequence (mod 10)
        fibonacci_last_digits.push_back(
            (fibonacci_last_digits[i - 1] + fibonacci_last_digits[i - 2]) % 10);
    }

    return fibonacci_last_digits;
}


// Finds the sum of the last digits of a fibonacci sequence till n using the
// naive way
unsigned int get_fibonacci_partial_sum_fast(unsigned long long from,
                                            unsigned long long to) {
    unsigned long long sum = 0, from_remainder = from % PISANO_PERIOD,
                       to_remainder = to % PISANO_PERIOD;

    fibonacci_last_digits = generate_fibonacci_sequence(PISANO_PERIOD);

    // find the sum of fibonacci last digits
    for (unsigned int i = from_remainder; i != to_remainder + 1;
         i = (i + 1) % (PISANO_PERIOD + 1)) {
        sum += fibonacci_last_digits[i];
        sum %= 10;
    }

    return sum;
}


int main() {
    long long from, to;
    cin >> from >> to;
    // cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
    cout << get_fibonacci_partial_sum_fast(from, to) << "\n";
}
