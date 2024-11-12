#include <iostream>
#include <vector>
using namespace std;

int knapSackDP(vector<int>& values, vector<int>& weights, int capacity, int n) {
    vector <vector <int>> dp (n+1, vector <int>(capacity+1, 0));

    for (int i=1; i<=n; i++) {
        for (int w=0; w<=capacity; w++) {
            if (weights[i-1] <= w) {
                dp[i][w] = max(dp[i-1][w], dp[i-1][w - weights[i-1]]+values[i-1]);
            }
            else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    cout << "Enter the capacity of the Knapsack : ";
    int c;
    cin >> c;
    cout << "Enter the number of items : ";
    int n;
    cin >> n;
    
    vector <int> values(n), weights(n);

    for (int i=0; i<n; i++) {
        cout << "Item " << i+1 << " : " << endl;
        cout << "Enter the weight of the item : ";
        cin >> weights[i];
        cout << "Enter the value of the item : ";
        cin >> values[i];
    }

    int max = knapSackDP(values, weights, c, n);

    cout << max;

    return 0;
}