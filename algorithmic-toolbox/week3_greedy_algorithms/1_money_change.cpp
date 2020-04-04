#include <iostream>

using namespace std;


int get_change(int money) {
    unsigned int coin_count = 0;
    // find number of 10 rupee coins
    coin_count += money / 10;
    // reduce the money remaining
    money %= 10;

    // find the number of 5 rupee coins
    coin_count += money / 5;
    // reduce the money remaining
    money %= 5;

    // find the number of 1 rupee coins
    coin_count += money;

    return coin_count;
}

int main() {
    int m;
    cin >> m;
    cout << get_change(m) << '\n';
}
