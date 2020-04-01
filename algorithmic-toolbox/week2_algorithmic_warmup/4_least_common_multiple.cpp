#include <iostream>


using namespace std;


// compute the LCM of two numbers in the bruteforce way
long long lcm_naive(long long a, long long b) {
    for (long l = 1; l <= a * b; ++l)
        if (l % a == 0 && l % b == 0)
            return l;

    return a * b;
}


// Compute the GCD of two numbers using Euclid's algorithm fast
long long gcd_fast(long long a, long long b) {
    a = llabs(a);
    b = llabs(b);

    if (b == 0)
        return a;

    else if (a == 0)
        return b;

    else
        gcd_fast(b, a % b);
}


// Compute LCM using GCD
long long lcm_fast(long long a, long long b) { return (a * b) / gcd_fast(a, b); }


void test_solution() {
    int naive, fast;
    for (int n = 1; n < 100; ++n)
        for (int m = 1; m < 100; ++m) {
            cout << m << n << '\n';
            naive = lcm_naive(m, n);
            fast = lcm_fast(m, n);
            cout << "Naive: " << naive;
            cout << "Fast: " << fast << '\n';

            if (fast != naive) {
                cout << "Error!!!\n";
                exit(1);
            }
        }
}


int main() {
    long long a, b;
    std::cin >> a >> b;
    std::cout << lcm_fast(a, b) << std::endl;
    return 0;
}
