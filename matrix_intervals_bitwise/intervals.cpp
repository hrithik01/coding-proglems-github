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


ARROW POINT SHOTS
There are some spherical balloons taped onto a flat wall that represents the XY-plane. 
The balloons are represented as a 2D integer array points where points[i] = [xstart, xend] denotes a balloon whose horizontal diameter stretches between xstart and xend. 
You do not know the exact y-coordinates of the balloons.
Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis. 
A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend.
 There is no limit to the number of arrows that can be shot.
 A shot arrow keeps traveling up infinitely, bursting any balloons in its path.
Given the array points, return the minimum number of arrows that must be shot to burst all balloons.

Example 1:
Input: points = [[10,16],[2,8],[1,6],[7,12]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
- Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].
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


    // Determine if two intervals overlap and return the overlapping segment
    // Returns {true, {start, end}} if they overlap; otherwise {false, {}}
    pair<bool, vector<int>> findOverlap(const vector<int>& a, const vector<int>& b) {
        // Calculate the intersection boundaries
        int start = max(a[0], b[0]);
        int end   = min(a[1], b[1]);
        // Overlap exists when the computed start is not past the end
        if (start <= end) {
            return { true, { start, end } };
        }
        // No overlap
        return { false, {} };
    }
    int findMinArrowShots(vector<vector<int>>& arr) {
        int n = arr.size();
        // In the worst case, we need one arrow per balloon
        int ans = n;
        // Sort balloons by their start coordinate
        sort(arr.begin(), arr.end(), fn);
        // Initialize the current overlapping range to the first balloon
        vector<int> curr = arr[0];
        // Process each subsequent balloon
        for (int i = 1; i < n; i++) {
            // Check if it overlaps with the current range
            auto res = findOverlap(curr, arr[i]);
            if (res.first) {
                // Overlap found: reuse an arrow and shrink the shooting range
                ans--;
                curr = move(res.second);
            } else {
                // No overlap: must use a new arrow starting at this balloon
                curr = arr[i];
            }
        }
        return ans;
    }


    static bool fn2(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
    int findMinArrowShotsOptimised(vector<vector<int>>& points) {
        int n = points.size();
        if (n == 0) return 0;
        // Sort balloons by their x-end so we always shoot at the earliest end
        sort(points.begin(), points.end(), fn2);
        // We need at least one arrow; shoot it at the end of the first balloon
        int arrows = 1;
        int currEnd = points[0][1];
        // Scan remaining balloons
        for (int i = 1; i < n; i++) {
            // If this balloon starts within the range of the current arrow
            if (points[i][0] <= currEnd) {
                // Narrow down the current shooting position to the minimum end
                currEnd = min(currEnd, points[i][1]);
            }
            // Otherwise we need a new arrow for this balloon
            else {
                arrows++;
                currEnd = points[i][1];
            }
        }
        return arrows;
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