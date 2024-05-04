#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(result, current, candidates, target, 0);
        return result;
    }

    void backtrack(vector<vector<int>>& result, vector<int>& current, vector<int>& candidates, int target, int start) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        if (target < 0) {
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            current.push_back(candidates[i]);
            backtrack(result, current, candidates, target - candidates[i], i);
            current.pop_back();
        }
    }

    // If the problem is changed to find the number of combinations that add up to the target (without needing to return the actual combinations), a dynamic programming approach can be used to optimize the solution to O(N*T) time complexity and O(T) space complexity.
    int combinationSumDP(vector<int>& candidates, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int candidate : candidates) {
            for (int i = candidate; i <= target; i++) {
                dp[i] += dp[i - candidate];
            }
        }
        return dp[target];
    }

    void print(vector<vector<int>>& result) {
        for (auto v : result) {
            for (auto i : v) {
                cout << i << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    vector<int> vec = {2, 3, 5, 6, 7, 11, 13};
    int target = 13;
    Solution sol;
    vector<vector<int>> result = sol.combinationSum(vec, target);
    int resultDP = sol.combinationSumDP(vec, target);
    sol.print(result);
    cout << "Dynamic Programming" << endl;
    cout << resultDP << endl;
    return 0;
}