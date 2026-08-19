#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

struct CoinChangeResult {
    bool possible;
    int minCoins;
    std::vector<int> coinsUsed;
};

/**
 * Computes the minimum number of coins and backtracks the coins used.
 * Algorithm: Bottom-Up Dynamic Programming (Tabulation)
 */
CoinChangeResult getMinCoins(const std::vector<int>& coins, int amount) {
    if (amount == 0) {
        return {true, 0, {}};
    }

    // dp[i] stores the minimum coins needed for amount i
    // coinUsed[i] stores the coin denomination chosen for amount i
    std::vector<int> dp(amount + 1, INT_MAX);
    std::vector<int> coinUsed(amount + 1, -1);

    // Base Case
    dp[0] = 0;

    // Fill DP table
    for (int i = 1; i <= amount; ++i) {
        for (int coin : coins) {
            if (coin <= i && dp[i - coin] != INT_MAX) {
                if (dp[i - coin] + 1 < dp[i]) {
                    dp[i] = dp[i - coin] + 1;
                    coinUsed[i] = coin;
                }
            }
        }
    }

    // If unreachable
    if (dp[amount] == INT_MAX) {
        return {false, -1, {}};
    }

    // Backtrack to reconstruct the combination
    std::vector<int> chosenCoins;
    for (int curr = amount; curr > 0; curr -= coinUsed[curr]) {
        chosenCoins.push_back(coinUsed[curr]);
    }

    return {true, dp[amount], chosenCoins};
}

void printResult(const CoinChangeResult& result) {
    std::cout << "\n----------------------------------------\n";
    std::cout << "            PRACTICAL RESULT            \n";
    std::cout << "----------------------------------------\n";

    if (!result.possible) {
        std::cout << "Result: Change cannot be made with given coins.\n";
    } else {
        std::cout << "Minimum number of coins: " << result.minCoins << "\n";
        std::cout << "Coins used             : ";
        for (int coin : result.coinsUsed) {
            std::cout << coin << " ";
        }
        std::cout << "\n";
    }

    std::cout << "----------------------------------------\n\n";
}

int main() {
    std::cout << "========================================\n";
    std::cout << "  DYNAMIC PROGRAMMING: COIN CHANGE      \n";
    std::cout << "========================================\n";

    int n;
    std::cout << "Enter number of coin types: ";
    if (!(std::cin >> n) || n <= 0) {
        std::cerr << "Invalid number of coins!\n";
        return 1;
    }

    std::vector<int> coins(n);
    std::cout << "Enter coin values (space-separated): ";
    for (int i = 0; i < n; ++i) {
        std::cin >> coins[i];
    }

    int amount;
    std::cout << "Enter target amount: ";
    if (!(std::cin >> amount) || amount < 0) {
        std::cerr << "Invalid target amount!\n";
        return 1;
    }

    CoinChangeResult result = getMinCoins(coins, amount);
    printResult(result);

    return 0;
}
