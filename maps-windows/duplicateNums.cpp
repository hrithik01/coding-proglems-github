/*
Given an integer array nums and an integer k, 
return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++) {
            int t = nums[i];
            if(mp.count(t) && i - mp[t] <= k) return true;
            mp[t] = i;
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 1};
    int k = 3;
    bool result = s.containsNearbyDuplicate(nums, k);
    cout << (result ? "true" : "false") << endl; // Output: true
    nums = {1, 0, 1, 1};
    k = 1;
    result = s.containsNearbyDuplicate(nums, k);
    cout << (result ? "true" : "false") << endl; // Output: true
    nums = {1, 2, 3, 1, 2, 3};
    k = 2;
    result = s.containsNearbyDuplicate(nums, k);
    cout << (result ? "true" : "false") << endl; // Output: false
    return 0;
}