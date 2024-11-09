#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int frogJump2(vector<int>& stones) {
    int ans = 0, n=stones.size();
    for(int i=2; i<n; i++) {
        ans = max(ans, stones[i] - stones[i-2]);
    }
    return ans;
}

int main() {
    vector<int> stones = {0, 3, 5, 9, 12, 15, 17};
    cout<<frogJump2(stones)<<endl;
    return 0;
}

