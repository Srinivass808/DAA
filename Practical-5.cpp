#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to solve 0/1 Knapsack problem
void knapsack(vector<int> weights, vector<int> values, int capacity)
{
    int n = weights.size();

    // dp[i][w] stores the maximum value
    // using first i items with capacity w
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Build the DP table
    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= capacity; w++)
        {
            // If current item can fit
            if (weights[i - 1] <= w)
            {
                // Maximum of:
                // 1. Not taking the item
                // 2. Taking the item
                dp[i][w] = max(
                    dp[i - 1][w],
                    values[i - 1] + dp[i - 1][w - weights[i - 1]]
                );
            }
            else
            {
                // Current item cannot fit
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "Maximum value: "
         << dp[n][capacity] << endl;

    // Find which items were selected
    cout << "Items selected: ";

    int w = capacity;

    for (int i = n; i > 0; i--)
    {
        // If value is different, item was selected
        if (dp[i][w] != dp[i - 1][w])
        {
            cout << i << " ";
            w = w - weights[i - 1];
        }
    }

    cout << endl;
}

int main()
{
    int n;
    int capacity;

    cout << "Enter number of items: ";
    cin >> n;

    vector<int> weights(n);
    vector<int> values(n);

    cout << "Enter weights of items: ";

    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }

    cout << "Enter values of items: ";

    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    knapsack(weights, values, capacity);

    return 0;
}
