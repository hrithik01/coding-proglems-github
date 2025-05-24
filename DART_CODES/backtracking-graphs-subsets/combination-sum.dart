// DART_CODES/backtracking-graphs-subsets/combination-sum.dart
// Converted from C++
// Logic and comments preserved

class Solution {
  List<List<int>> combinationSum(List<int> candidates, int target) {
    List<List<int>> result = [];
    List<int> current = [];
    backtrack(result, current, candidates, target, 0);
    return result;
  }

  void backtrack(List<List<int>> result, List<int> current, List<int> candidates, int target, int start) {
    if (target == 0) {
      result.add(List.from(current));
      return;
    }
    if (target < 0) {
      return;
    }
    for (int i = start; i < candidates.length; i++) {
      current.add(candidates[i]);
      backtrack(result, current, candidates, target - candidates[i], i);
      current.removeLast();
    }
  }

  // If the problem is changed to find the number of combinations that add up to the target (without needing to return the actual combinations), a dynamic programming approach can be used to optimize the solution to O(N*T) time complexity and O(T) space complexity.
  int combinationSumDP(List<int> candidates, int target) {
    List<int> dp = List.filled(target + 1, 0);
    dp[0] = 1;
    for (int candidate in candidates) {
      for (int i = candidate; i <= target; i++) {
        dp[i] += dp[i - candidate];
      }
    }
    return dp[target];
  }

  void print(List<List<int>> result) {
    for (var v in result) {
      print(v.join(' '));
    }
  }
}
