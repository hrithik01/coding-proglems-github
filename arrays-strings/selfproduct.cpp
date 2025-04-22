#include <iostream>

using namespace std;

class Solution {
    public:
        vector<int> productExceptSelf1(vector<int>& nums) {
            int n = nums.size();
            vector<int> l2r(n, 1), r2l(n, 1), ans(n, 1);

            this->printVector(l2r);
            this->printVector(r2l);
    
            // && is needed to check both i and j are in bounds
            for(int i=1, j=n-2; i<n && j>=0; i++, j--) {
                l2r[i] = l2r[i-1] * nums[i-1];
                r2l[j] = r2l[j+1] * nums[j+1];
            }
            this->printVector(l2r);
            this->printVector(r2l);
            for(int i=0; i<n; i++) {
                ans[i] = l2r[i] * r2l[i];
            }
            return ans;
        }

        // This is the optimized version of the above code, although time complexity is same O(n) but space complexity is reduced to O(n) from O(3n)
        vector<int> productExceptSelf(vector<int>& nums) {
            int n = nums.size();
            vector<int> ans(n, 1);
            int left = 1, right = 1;

            for (int i = 0; i < n; i++) {
                ans[i] *= left;
                left *= nums[i];
            }
            this->printVector(ans);
            for (int j = n - 1; j >= 0; j--) {
                ans[j] *= right;
                right *= nums[j];
            }
            return ans;
        }

        void printVector(vector<int>& nums) {
            cout << "Vector: "<< endl;
            for (int i = 0; i < nums.size(); i++) {
                cout << nums[i] << " ";
            }
            cout << endl;
        }
    };

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = s.productExceptSelf(nums);
    s.printVector(result);
    cout << endl;
    return 0;
}