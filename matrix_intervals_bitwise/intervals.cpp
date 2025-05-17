/*
MERGE INTERVALS
Given an array of intervals where intervals[i] = [starti, endi],
merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
Example 1:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].


INSERT INTERVAL
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval
 and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.
Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).
Return intervals after the insertion.
Note that you don't need to modify intervals in-place. You can make a new array and return it.
Example 1:
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // Comparator: sort intervals by their start time
    static bool fn(const vector<int> &a, const vector<int> &b)
    {
        return a[0] < b[0];
    }

    vector<vector<int>> mergeIntervals(vector<vector<int>> &arr)
    {
        if (arr.empty())
            return {};
        // sort intervals by start
        sort(arr.begin(), arr.end(), fn);
        // idx points to the end of the merged list in-place
        int idx = 0;
        // iterate and merge into arr[0..idx]
        for (int i = 1; i < arr.size(); i++)
        {
            // overlapping interval → extend the current merged interval
            if (arr[i][0] <= arr[idx][1])
            {
                arr[idx][1] = max(arr[idx][1], arr[i][1]);
            }
            // disjoint interval → move idx forward and copy
            else
            {
                idx++;
                arr[idx] = arr[i];
            }
        }
        // resize to keep only merged intervals
        arr.resize(idx + 1);
        return arr;
    }

    vector<vector<int>> insertInterval(vector<vector<int>> &arr, vector<int> &ni)
    {
        // Add the new interval at the end
        arr.push_back(ni);

        // Bubble the newly added interval to its correct sorted position by start time
        for (int i = arr.size() - 1; i > 0; i--)
        {
            // If current interval starts before the previous one, swap them
            if (arr[i][0] < arr[i - 1][0])
                swap(arr[i], arr[i - 1]);
            else
                // Once correctly placed, stop bubbling
                break;
        }

        vector<vector<int>> ans;
        // Start with the first (smallest-start) interval
        vector<int> curr = arr[0];

        // Iterate through all intervals to merge overlaps
        for (int i = 1; i < arr.size(); i++)
        {
            // If current interval overlaps with arr[i], extend its end
            if (curr[1] >= arr[i][0])
            {
                curr[1] = max(curr[1], arr[i][1]);
            }
            else
            {
                // No overlap: save the completed interval and move to the next
                ans.push_back(curr);
                curr = arr[i];
            }
        }

        // Push the last interval after merging
        ans.push_back(curr);
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> merged = sol.mergeIntervals(intervals);
    for (const auto &interval : merged)
    {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    vector<int> newInterval = {2, 5};
    vector<vector<int>> inserted = sol.insertInterval(intervals, newInterval);
    for (const auto &interval : inserted)
    {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}

/*
Overall Approach:
- Sort intervals by start time (O(n log n)).
- Merge in-place: maintain a write-pointer (idx) for the merged portion.
- For each interval, either merge with arr[idx] or advance idx and write the new interval.
- Finally resize the input array to contain only merged intervals.

Time Complexity: O(n log n) due to sorting.
Space Complexity: O(1) extra (in-place merging) + O(log n) for sort call stack.
*/