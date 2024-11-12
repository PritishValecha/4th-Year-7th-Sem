#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct item {
    int weight;
    double value;
};

bool compare (item a, item b) {
    double r1 = a.value/a.weight;
    double r2 = b.value/b.weight;
    return r1>r2;
}

double fractionalKnapsack (vector <item> items, int capacity) {
    sort(items.begin(), items.end(), compare);
    
    double max = 0.0;

    for(const auto &item : items) {
        if(capacity >= item.weight) {
            capacity -= item.weight;
            max += item.value;
        }
        else {
            double t = double(capacity)/double(item.weight);
            max += item.value*t;
            break;
        }
    }

    return max;
}

int main() {
    cout << "Enter the amount of items : ";
    int n;
    cin >> n;
    cout << "Enter the Knapsack capacity : ";
    int c;
    cin >> c;
    vector <item> items;
    item it;
    for (int i=0; i<n; i++) {
        cout << "Enter the weight of the " << i+1 << " item : ";
        cin >> it.weight;
        cout << "Enter the value of the " << i+1 << " item : ";
        cin >> it.value;
        items.push_back(it);
    }

    double max = fractionalKnapsack(items, c);
    cout << max;

    return 0;
}