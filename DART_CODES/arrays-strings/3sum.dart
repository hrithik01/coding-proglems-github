// DART_CODES/arrays-strings/3sum.dart
// Converted from C++
// Logic and comments preserved
/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.
*/

List<List<int>> threeSum(List<int> nums) {
  int n = nums.length;
  List<List<int>> ans = [];
  nums.sort();
  for (int i = 0; i < n; i++) {
    if (i > 0 && nums[i] == nums[i - 1]) continue;
    int j = i + 1, k = n - 1;
    while (j < k) {
      int sum = nums[i] + nums[j] + nums[k];
      if (sum < 0) {
        j++;
      } else if (sum > 0) {
        k--;
      } else {
        ans.add([nums[i], nums[j], nums[k]]);
        while (j < k && nums[j] == nums[j + 1]) j++;
        while (j < k && nums[k] == nums[k - 1]) k--;
        j++;
        k--;
      }
    }
  }
  return ans;
}

void main() {
  List<int> nums = [-1, 0, 1, 2, -1, -4];
  print(threeSum(nums));
}
