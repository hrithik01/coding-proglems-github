/**
 * @file
 * @brief This file contains an implementation of the knapsack problem using dynamic programming.
 * 
 * The knapsack problem is a classic optimization problem in computer science and mathematics.
 * Given a set of items, each with a weight and a value, determine the most valuable combination
 * of items that can be carried in a knapsack of limited capacity.
 * 
 * This implementation uses dynamic programming to solve the knapsack problem. It creates a 2D
 * table to store the maximum value that can be obtained for each subproblem. The table is filled
 * in a bottom-up manner, starting from the smallest subproblem and gradually building up to the
 * original problem.
 * 
 * Summary:
 * - The knapsack function takes the maximum weight capacity of the knapsack, a vector of item weights,
 *   and a vector of item values as input.
 * - It returns the maximum value that can be obtained by selecting a combination of items that fits
 *   within the weight capacity of the knapsack.
 * 
 * Example:
 * @code
 * int W = 10;
 * std::vector<int> weights = {2, 3, 4, 5};
 * std::vector<int> values = {3, 4, 5, 6};
 * 
 * int max_value = knapsack(W, weights, values);
 * std::cout << "Maximum value: " << max_value << std::endl;
 * @endcode
 */

#include <iostream>
#include <vector>

/**
 * @brief Solves the knapsack problem using dynamic programming.
 * @param W The maximum weight capacity of the knapsack.
 * @param weights A vector of item weights.
 * @param values A vector of item values.
 * @return The maximum value that can be obtained by selecting a combination of items that fits within
 *         the weight capacity of the knapsack.
 */
using namespace std;

int knapsack(int W, const vector<int>& weights, const vector<int>& values) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int W = 10;
    std::vector<int> weights = {2, 3, 4, 5};
    std::vector<int> values = {3, 4, 5, 6};

    int max_value = knapsack(W, weights, values);
    std::cout << "Maximum value: " << max_value << std::endl;

    return 0;
}
