#include <iostream>
#include <vector>

using namespace std;

int knapsackDP(int capacity, vector <int> weights, vector <int> values, int n) {
    vector <vector <int>> dp(n+1, vector<int>(capacity+1, 0));

    for (int i=1; i<=n; i++) {
        for (int w=0; w<capacity; w++) {
            if (w >= weights[i-1]) {
                dp[i][w] = max(dp[i-1][w], dp[i-1][w-weights[i]]+values[i-1]); 
            }
            else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    return dp[n][capacity];
}

int main() {
    int n, c;
    cout << "Enter the capacity of the sack : ";
    cin >> c;
    cout << "Enter the total number of items : ";
    cin >> n;

    vector <int> values(n), weights(n);
    for (int i=0; i<n; i++) {
        cout << "Item " << i+1 << " : " << endl;
        cout << "Enter the weight of item " << i+1 << " : ";
        cin >> weights[i];
        cout << "Enter the value of item " << i+1 << " : ";
        cin >> values[i];
    }

    int max = knapsackDP(c, weights, values, n);
    cout << "The maximum capacity is : " << max;

    return 0;
}