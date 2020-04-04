#include <iostream>
#include <vector>

using namespace std;


int compute_min_refills(int dist, unsigned int tank, vector<unsigned long long> & stops) {
    unsigned long long current_refill = 0, last_refill = 0, length = stops.size() - 1;
    long long refill_count = 0;

    while(current_refill < length) {
        last_refill = current_refill;

        while((current_refill < length) && ((stops[current_refill + 1] - stops[last_refill]) <= tank)) {
            ++current_refill;
        }

        // return impossible if cannot reach next refill/stop
        if(current_refill == last_refill)
            break;

        // return refill count if we reach the end
        if(current_refill == length)
            return refill_count;

        ++refill_count;
    }

    return -1;
}


int main() {
    unsigned long long distance = 0;
    cin >> distance;
    unsigned int mileage = 0;
    cin >> mileage;
    int stop_count = 0;
    cin >> stop_count;

    // make the stops list
    vector<unsigned long long> stops(stop_count + 2);
    // add the starting point to the list
    stops[0] = 0;
    // take the rest of the stops as inputs
    for (int i = 1; i < (stop_count + 1); ++i)
        cin >> stops.at(i);
    // add the last stop
    stops[stop_count + 1] = distance;

    cout << compute_min_refills(distance, mileage, stops) << "\n";

    return 0;
}
