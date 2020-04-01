#include <iostream>
#include <math.h>
#include <cassert>


using namespace std;


// Compute the GCD of two numbers in the slow way
int gcd_naive(int a, int b) {
    int current_gcd = 1;
    for (int d = 2; d <= a && d <= b; d++) {
        if (a % d == 0 && b % d == 0) {
            if (d > current_gcd) {
                current_gcd = d;
            }
        }
    }
    return current_gcd;
}


// Compute the GCD of two numbers using Euclid's algorithm fast
int gcd_fast(int a, int b) {
    a = abs(a);
    b = abs(b);

    if (b == 0)
        return a;

    else if (a == 0)
        return b;

    else
      gcd_fast(b, a % b);
}


void test_solution() {
    int naive, fast;
    for (int n = 1; n < 1000; ++n)
        for (int m = 1; m < 1000; ++m) {
            cout << m << n << '\n';
            naive = gcd_naive(m, n);
            fast = gcd_fast(m, n);
            cout << "Naive: " << naive;
            cout << "Fast: " << fast << '\n';

            if (fast != naive) {
                cout << "Error!!!\n";
                exit(1);
            }
        }
}


int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << gcd_fast(a, b) << std::endl;
    // test_solution();
    return 0;
}
