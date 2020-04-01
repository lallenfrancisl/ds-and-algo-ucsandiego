#include <iostream>


/**
  * Finds the last digit of the nth fibonacci number in the naive way
**/
u_int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}


/**
  * Finds the last digit of the nth fibonacci number efficiently
**/
u_int get_fibonacci_last_digit_fast(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
    }

    return current;
}


int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_fast(n);
    std::cout << c << '\n';

    return 0;
}
