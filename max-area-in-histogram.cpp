/*

Given an array of integers, heights, that represents the heights of bars in a histogram, find the area of the largest rectangle in the histogram, where the rectangle has a constant width of 
1 unit for each bar.

Constraints
1≤heights.length ≤10^5

*/
#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>
using namespace std;

int max_area_histogram (vector<int> heights) {
    int n = heights.size();
    stack<int> st;
    int max_area = 0;

    // Using stack to store the indices of the heights in increasing order, And checking the are for the bars that are not there in the stack
    for(int i=0; i<=n; i++) {

        while(!st.empty() && (i==n || heights[st.top()] > heights[i])) {

            int height = heights[st.top()];
            st.pop();

            int width = st.empty() ? i : i-st.top()-1;
            max_area = max(max_area, height*width);
        }
        st.push(i);
    }
    return max_area;
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << max_area_histogram(heights) << endl;
    return 0;
}