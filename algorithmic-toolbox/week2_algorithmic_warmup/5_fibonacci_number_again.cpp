#include <iostream>
#include <vector>


using namespace std;


// initialize a list of the modulus of the fibonacci series
vector <unsigned long long> fibonacci_mod_m;


unsigned long long get_fibonacci_huge_naive(unsigned long long n, unsigned long long m) {
    if (n <= 1)
        return n;

    unsigned long long previous = 0;
    unsigned long long current = 1;

    for (unsigned long long i = 0; i < n - 1; ++i) {
        unsigned long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}


unsigned long long pisano_period(unsigned long long m) {
    unsigned long long pisano_per = 0;
    for (unsigned long long i = 2; i <= m * m; ++i) {
        // generate the fibonacci sequence (mod m) as we go along
        fibonacci_mod_m.push_back((fibonacci_mod_m[i - 1] + fibonacci_mod_m[i - 2]) % m);

        // check for pisano periodicity
        if ((fibonacci_mod_m [i - 1] == 0) && (fibonacci_mod_m[i] == 1)) {
            // reduced by 1 since if we found it is periodic now then the period must have started at the
            // one before
            pisano_per = i - 1;
            break;
        }
    }

    return pisano_per;
}


unsigned long long get_fibonacci_huge_fast(unsigned long long n, unsigned long long m) {
    return fibonacci_mod_m[n % pisano_period(m)];
}


int main() {
    unsigned long long n, m;
    cin >> n >> m;
    fibonacci_mod_m.push_back(0);
    fibonacci_mod_m.push_back(1);
    // cout << "Naive: " << get_fibonacci_huge_naive(n, m) << '\n';
    cout << get_fibonacci_huge_fast(n, m) << '\n';

    return 0;
}
