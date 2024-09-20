#include <iostream>
#include <vector>

using namespace std;

class peakElement {
    public:
        vector<int> Naive(vector<int>& arr) {
            int n = arr.size();
            vector<int> ans;
            if(n==1) {
                ans.push_back(arr[0]);
                return ans;
            }
            if(arr[0] > arr[1]) ans.push_back(arr[0]);
            if(arr[n-1] > arr[n-2]) ans.push_back(arr[n-1]);
            for(int i=1; i<n-1; i++) {
                if(arr[i] > arr[i-1] && arr[i] > arr[i+1])
                    ans.push_back(arr[i]);
            }
            return ans;
        }

        vector<int> Optimized(vector<int>& arr) {
            int n = arr.size();
            vector<int> ans;
            if(n==1) {
                ans.push_back(arr[0]);
                return ans;
            }
            if(arr[0] > arr[1]) ans.push_back(arr[0]);
            else if(arr[n-1] > arr[n-2]) ans.push_back(arr[n-1]);
            else {
                int l=1, r=n-2;
                while(l<=r) {
                    int m=l+(r-l)/2;
                    if(arr[m] > arr[m-1] && arr[m] > arr[m+1]) {
                        ans.push_back(arr[m]);
                        break;
                    } 
                    else if(arr[m-1] > arr[m]) r=m-1;
                    else l=m+1;
                }
            }
            return ans;
        }
};

int main() {
    peakElement obj;
    vector<int> arr = { 0, 1, 2, 3, 9, 3, 2 };
    // vector<int> ans = obj.Naive(arr);
    vector<int> ans = obj.Optimized(arr);
    for(auto i : ans) cout << i << " ";
    cout<<endl;
    return 0;
}