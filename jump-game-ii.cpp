#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * Jump Game II
 * 
 * Problem: Given an array nums where each element represents the maximum jump distance from that position,
 * find the minimum number of jumps needed to reach the last element.
 * 
 * Example: Input: nums = [2,3,1,1,4]  Output: 2
 * Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
 */

int jump(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) return 0; // Already at the end

    int jumps = 0;       // Count of jumps
    int currEnd = 0;     // The furthest position that can be reached with current number of jumps
    int currFarthest = 0; // The furthest position that can be reached with current number of jumps + 1

    // We don't need to process the last element as we only need to reach it, not jump from it
    for (int i = 0; i < n - 1; i++) {
        // Update the furthest we can reach
        currFarthest = max(currFarthest, i + nums[i]);
        
        // If we've reached the end of current jump range
        if (i == currEnd) {
            // We need to jump
            jumps++;
            // Update the end of the current jump range
            currEnd = currFarthest;
            
            // If we can already reach the end, break
            if (currEnd >= n - 1) break;
        }
    }
    
    return jumps;
}

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << "Minimum jumps needed: " << jump(nums) << endl;
    
    vector<int> nums2 = {2, 3, 0, 1, 4};
    cout << "Minimum jumps needed: " << jump(nums2) << endl;
    
    return 0;
}

// Time Complexity: O(n), where n is the length of the array
// Space Complexity: O(1), we only use a constant amount of extra space