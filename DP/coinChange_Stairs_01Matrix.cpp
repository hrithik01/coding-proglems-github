#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

int coinChange(vector<int>& coins, int total) {
    vector<int> dp(total+1, total+1);
    dp[0] = 0;
    for(int i=1; i <= total; i++) {
        for(int coin: coins) {
            if(coin <= i) {
                dp[i] = min(dp[i], dp[i-coin] + 1);
            }
        }
    }
    return dp[total] > total ? -1 : dp[total];
}

int main () {
    cout<<"Hello From Hrithik \n";
    vector<int> coins = {2, 4};
    int ans = coinChange(coins, 11);
    cout<<ans<<endl;
    return 0;
}
