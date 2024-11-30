#include <iostream>
#include <vector>

using namespace std;

vector<int> sweet(vector<int> s)
{
    int n = s.size();
    vector<int> swts(n, 0);
    vector<int> ans(n, 0);
    for(int i=0; i<n; i++) {
        swts[i] = n;
        for(int j=0; j<i; j++)
            swts[j]--;
        for(int j=0; j<=i; j++) {
            if(swts[j] > n - s[i])
                ans[j] = 1;
        }
    }
    return ans;
}

int main() {

    return 0;
}