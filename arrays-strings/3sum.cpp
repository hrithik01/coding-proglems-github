/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            int n = nums.size();
            vector<vector<int>> ans;
            sort(nums.begin(), nums.end());
            
            for(int i = 0; i < n; i++) {
                // Skip duplicates for i
                if(i > 0 && nums[i] == nums[i-1]) continue;
                
                int j = i + 1, k = n - 1;
                while(j < k) {
                    int sum = nums[i] + nums[j] + nums[k];
                    
                    if(sum < 0) {
                        j++;
                    } else if(sum > 0) {
                        k--;
                    } else {
                        ans.push_back({nums[i], nums[j], nums[k]});
                        
                        // Skip duplicates for j and k
                        while(j < k && nums[j] == nums[j+1]) j++;
                        while(j < k && nums[k] == nums[k-1]) k--;
                        
                        j++;
                        k--;
                    }
                }
            }
            return ans;
        }
    };

int main() {
    Solution sol;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = sol.threeSum(nums);
    cout << "Triplets that sum to zero:" << endl;
    for(const auto& triplet : result) {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << endl;
    }
    cout << endl;
    return 0;
}