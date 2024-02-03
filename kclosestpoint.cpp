/*
Given a list of points on a plane, where the plane is a 2-D array with (x, y) coordinates, find the 
k closest points to the origin 
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int main () {
    vector<vector<int>> points = {{1, 3}, {-2, 2}, {5, 8}, {0, 1}};
    int k = 2;

    //max heap by default
    priority_queue<pair<int, int>> pq;
    for(int i = 0; i < points.size(); i++) {
        int x = points[i][0];
        int y = points[i][1];
        int dist = x*x + y*y;
        pq.push({dist, i});
        if(pq.size() > k) {
            pq.pop();
        }
    }
    vector<vector<int>> ans;
    while(!pq.empty()) {
        ans.push_back(points[pq.top().second]);
        pq.pop();
    }
    for(vector<int> v: ans) {
        cout << v[0] << " " << v[1] << endl;
    }
    return 0;
}