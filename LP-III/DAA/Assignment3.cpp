#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an item with weight and value
struct Item {
    int weight;
    int value;
};

// Comparator to sort items by value-to-weight ratio in descending order
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// Function to calculate the maximum value for the Fractional Knapsack
double fractionalKnapsack(int capacity, vector<Item>& items) {
    // Sort items by descending value-to-weight ratio
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;

    // Loop through all items
    for (const auto& item : items) {
        if (capacity >= item.weight) {
            // If the item can be fully taken, take it
            capacity -= item.weight;
            totalValue += item.value;
        } else {
            // If the item can't be fully taken, take the fractional part
            totalValue += item.value * ((double)capacity / item.weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    int n, capacity;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    vector<Item> items(n);
    cout << "Enter the weight and value of each item:\n";
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << ":\n";
        cout << "Weight: ";
        cin >> items[i].weight;
        cout << "Value: ";
        cin >> items[i].value;
    }

    double maxValue = fractionalKnapsack(capacity, items);
    cout << "Maximum value in the knapsack: " << maxValue << endl;

    return 0;
}
