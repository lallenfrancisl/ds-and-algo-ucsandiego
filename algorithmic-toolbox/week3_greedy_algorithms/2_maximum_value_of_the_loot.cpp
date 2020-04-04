#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// item class
class Item {
    public:
        double value_per_weight;
        double weight;
};


// function for sorting the array
bool comp(const Item a, const Item b) {
    return a.value_per_weight > b.value_per_weight;
}


double get_optimal_value(double capacity, vector<Item> items) {
    double value = 0.0;
    unsigned long long length = items.size(), current_item = 0;

    // sort the items
    sort(items.begin(), items.end(), comp);

    // go through the items and fill the knapsack with the item with the largest value per weight
    while ((current_item < length) && (capacity != 0)) {
        if (items[current_item].weight < capacity) {
            value += items[current_item].weight * items[current_item].value_per_weight;
            capacity -= items[current_item].weight;
        }
        else {
            value += capacity * items[current_item].value_per_weight;
            capacity = 0;
        }
        ++current_item;
    }

    return value;
}

int main() {
    unsigned long long n;
    double capacity;
    cin >> n >> capacity;
    vector<Item> items(n);

    // get the values and weights of the items
    for (unsigned long long i = 0; i < n; i++) {
        cin >> items[i].value_per_weight >> items[i].weight;
    }

    // convert the values got as input to values per weight
    for (unsigned long long i = 0; i < n; ++i) {
        items[i].value_per_weight /= items[i].weight;
    }

    // find the optimal value of the knapsack
    double optimal_value = get_optimal_value(capacity, items);

    cout.precision(10);
    cout << optimal_value << endl;
    return 0;
}
