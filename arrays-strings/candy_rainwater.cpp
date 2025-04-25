#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int candy(vector<int>& ratings) {
            int n = ratings.size();
            vector<int> candies(n, 1);
            for (int i = 1; i < n; ++i) {
                if (ratings[i] > ratings[i - 1]) {
                    candies[i] = candies[i - 1] + 1;
                }
            }
            for (int i = n - 2; i >= 0; --i) {
                if (ratings[i] > ratings[i + 1]) {
                    candies[i] = max(candies[i], candies[i + 1] + 1);
                }
            }
            int totalCandies = 0;
            for (int candy : candies) {
                totalCandies += candy;
            }
            return totalCandies;
        }
        void printVector(vector<int>& nums) {
            cout << "Vector: "<< endl;
            for (int i = 0; i < nums.size(); i++) {
                cout << nums[i] << " ";
            }
            cout << endl;
        }

        // O(n) time and O(1) space complexity
        // This is the optimized version of the above code, although time complexity is same O(n) but space complexity is reduced to O(1) from O(n)
        int candyOptimized(vector<int>& ratings) {\
            int n = ratings.size();
            if (n <= 1) return n;
            
            int totalCandies = 1;  // Start with 1 candy for first child
            int up = 0, down = 0, peak = 0;
            
            for (int i = 1; i < n; i++) {
                if (ratings[i] > ratings[i-1]) {  // Going up
                    up++;
                    down = 0;
                    peak = up;
                    totalCandies += up + 1;
                } 
                else if (ratings[i] == ratings[i-1]) {  // Equal rating
                    up = down = 0;
                    peak = 0;
                    totalCandies += 1;
                } 
                else {  // Going down
                    up = 0;
                    down++;
                    // If downward slope exceeds the previous peak, we need to give the peak one more candy
                    totalCandies += down + (peak >= down ? 0 : 1);
                }
                cout<<" i:" << i << " up:" << up << " down:" << down << " peak:" << peak << " totalCandies:" << totalCandies << endl;
            }
            
            return totalCandies;
        }
    
        int rain_water(vector<int>& height) {
            int n = height.size(), rmax = 0;
            vector<int> lmax(n, 0);
            lmax[0] = height[0];
            for(int i=1; i<n; i++) {
                lmax[i] = max(lmax[i-1], height[i]);
            }
            int ans = 0;
            for(int i=n-1; i>=0; i--) {
                rmax = max(rmax, height[i]);
                ans += (min(lmax[i], rmax) - height[i]);
            }
            return ans;
        }

        int rain_water_optimized(vector<int>& height) {
            int n = height.size();
            if (n <= 2) return 0; // Need at least 3 bars to trap water
            
            int left = 0, right = n - 1;
            int leftMax = 0, rightMax = 0;
            int result = 0;
            
            while (left < right) {
                // If left bar is smaller than right bar
                if (height[left] < height[right]) {
                    // If current left bar is higher than leftMax, update leftMax
                    if (height[left] >= leftMax) {
                        leftMax = height[left];
                    } else {
                        // Otherwise, add trapped water at this position
                        result += leftMax - height[left];
                    }
                    left++;
                } 
                // If right bar is smaller or equal to left bar
                else {
                    // If current right bar is higher than rightMax, update rightMax
                    if (height[right] >= rightMax) {
                        rightMax = height[right];
                    } else {
                        // Otherwise, add trapped water at this position
                        result += rightMax - height[right];
                    }
                    right--;
                }
            }
            
            return result;
        }
};

int main () {
    Solution s;
    vector<int> ratings = { 1, 2, 3, 3,2, 1 };
    // 1 2 1 1 3 2 1 2 3
    int result = s.candy(ratings);
    cout << "Total candies needed: " << result << endl;
    cout << endl;
    result = s.candyOptimized(ratings);
    cout << "Total candies needed (Optimized): " << result << endl;
    return 0;
}