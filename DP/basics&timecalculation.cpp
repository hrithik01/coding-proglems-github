#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

class Fibonacci {
    private:
        vector<int> dpmemo = vector<int>(100, 0);
    public:
        int recursion(int n) {
            if(n<=1) return n;
            return recursion(n-1) + recursion(n-2);
        }

        int tabulation_bottom_up(int n) {
            vector<int> dp(n+1, 0);
            dp[0] = 0;
            dp[1] = 1;
            for(int i=2; i<n+1; i++)
                dp[i] = dp[i-1] + dp[i-2];
            return dp[n];
        }

        int memoization_top_down(int n) {
            // Do not initialise dpmemo here, it will make the function slower
            if(n<=1) return n;
            if(dpmemo[n] != 0)
                return dpmemo[n];
            dpmemo[n] = memoization_top_down(n-1) + memoization_top_down(n-2);
            return dpmemo[n];
        }
};

class Pascals_Triangle {
    public:
        vector<vector<int>> generateCompleteTriangle(int numRows) {
            vector<vector<int>> result;
            for(int i=0; i<numRows; i++) {
                vector<int> row(i+1, 1);
                for(int j=1; j<i; j++) {
                    row[j] = result[i-1][j-1] + result[i-1][j];
                }
                result.push_back(row);
            }
            return result;
        }

        vector<int> generateLastRow(int row) {
            vector<int> result(row, 0);
            result[0] = 1;
            for(int i=1; i<row; i++) {
                for(int j=i; j>0; j--) {
                    result[j] += result[j-1];
                }
        }
        return result;
    }

        vector<int> lastRowStriverTechnique(int N) {
            vector<int> row(N, 0);
            row[0] = 1;
            for(int i=1; i<N; i++) {
                row[i] = row[i-1]*(N-i);
                row[i] = row[i]/i;
            }
            return row;
        }
};

int main() {
    cout<<"Hello from Hrithik \n";
    Fibonacci fib;
    int n = 20;

    clock_t start = clock();

    // int result = fib.recursion(n);
    // int result = fib.tabulation_bottom_up(n);
    int result = fib.memoization_top_down(n);

    clock_t end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);

    cout<<"Time taken by process is "<<time_taken<<endl;
    cout<<result<<endl;

    Pascals_Triangle pt;
    vector<vector<int>> result1 = pt.generateCompleteTriangle(5);
    for(auto v : result1) {
        for(auto i : v) {
            cout<<i<<" ";
        }
        cout<<endl;
    }

    // vector<int> result2 = pt.generateLastRow(5);
    vector<int> result2 = pt.lastRowStriverTechnique(5);
    cout<<"Last row: \n";
    for(auto i : result2) {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}