#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

// store n21 in vector
void n2oneRec(vector<int>& v, int n) {
    if(n==0) return;
    v.push_back(n);
    n2oneRec(v, n-1);
}

// Store first N fibonacci numbers
void fibonacci(vector<int>& arr, int n, int size) {
    if(size == n)
        return;
    arr.push_back(arr[size-1]+arr[size-2]);
    fibonacci(arr, n, size+1);
}
vector<int> generateFibonacciNumbers(int n) {
    vector<int> ans = {0, 1};
    if(n > 1)
        fibonacci(ans, n, 2);
    else if(n == 1)
        ans.pop_back();
    return ans;
}

// Factorial numbers less than N
void factn(vector<long long>& arr,  long long size, long long n) {
    long long nextFactorial = arr[size-1]*(size+1);
    if(nextFactorial>n) return;
    arr.push_back(nextFactorial);
    factn(arr, size+1, n);
}
vector<long long> factorialNumbers(long long n) {
    vector<long long> ans;
    ans.push_back(1);
    factn(ans, 1, n);
    return ans;
}

int main () {
    cout<<"Hello From Hrithik \n";
    int n;
    cout<<"Enter input \n";
    cin>>n;
    // vector<int> arr = generateFibonacciNumbers(n);
    vector<int> arr;
    n2oneRec(arr, n);
    for(int i: arr) {
        cout<<i<<" ";
    }
    cout<<"\nExecution over \n";
    return 0;
}