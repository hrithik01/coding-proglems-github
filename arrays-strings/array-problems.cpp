/*
You are given an array of ‘N’ non-negative integers 
where all elements appear an even number of times except two, 
print the two odd occurring elements in increasing order. 
It may be assumed that the size of the array is at-least two 
and there will always be exactly two numbers which appear an odd number of times
 in the given array. Odd occurence finding.
EXAMPLE:
Input: 'N' = 6, 'NUMS' = [1, 1, 2, 3, 4, 4]
Output: 2 3
*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector < int > detectOdd(int n, vector < int > nums) {
    int xorResult = 0;
    for (int i = 0; i < n; i++) {
        xorResult ^= nums[i];
    }

    // rightmostSetBit = X & -X
    int setBit = xorResult & ~(xorResult - 1);
    int num1 = 0, num2 = 0;

    /*
    Now that we have identified a bit position where A and B differ, we can use this to separate them.
    We iterate through the array again, this time using this bit to divide numbers into two groups:
    Numbers that have this bit set
    Numbers that don't have this bit set
    Why does this work?
    A will be in one group, B will be in the other.
    All other numbers (appearing even number of times) will be evenly split between these groups.
    SEGREGATING NUMBERS INTO TWO GROUPS WITH RIGHTMOST BIT SET AND NOT SET
    */

    for (int num : nums) {
        if (num & setBit) {
            num1 ^= num;
        } else {
            num2 ^= num;
        }
    }
    return num1<num2 ? vector<int>{ num1, num2 } : vector<int>{ num2, num1 };
}

// 1 3 5 7 2 4 6 (n=7, k=3) => 5
int findInteger(int n, int k) 
{
    int no_odds = (n+1)/2;
    return k <= no_odds ? 2*k - 1 : 2 * (k - no_odds);
}

/*
Problem statement
You are given an array ‘A’ containing a permutation ‘N’ numbers (0 ≤ A[i] < N). You are also given another array ‘B’ containing a permutation ‘M’ numbers (0 ≤ B[j] < M) and it is also given that N ≤ M.
For each element in array ‘A’ you need to find the first greater element to the right of the element in array ‘B’ that has the same value as the current array A’s element. In other words, for each ‘i’ from 0 to N - 1 in array ‘A’, you need to find an index ‘j’ in array ‘B’ such that A[i] = B[j], now you need to print the element that lies on the right of the j’th index and is also greater than B[j]. Print -1 if there is no greater element.
For Example :
If ‘N’ = 6, ‘A’ = {1, 2, 0, 3, 4, 5}, ‘M’ = 7 and ‘B’ = {3, 5, 0, 2, 1, 6, 4}.
Then, we will return {6, 6, 2, 5, -1, 6}
*/
vector<int> nextGreaterElement(int n, vector<int> A, int m, vector<int> B) {
    vector<int> arr(m, -1);
    stack<int> s;

    for(int i=m-1; i>=0; i--) {
        while(!s.empty() && s.top() <= B[i]) {
            s.pop();
        }
        if(!s.empty())
            arr[B[i]] = s.top();
        s.push(B[i]);
    }

    for(int i=0; i<A.size(); i++)
        A[i] = arr[A[i]];
    return A;
}


int main() {
    int n = 6;
    vector < int > nums = { 1, 1, 2, 3, 4, 4 };
    vector < int > result = detectOdd(n, nums);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}