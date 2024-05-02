#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

bool comparePairs(pair<char, int> p1, pair<char, int> p2) {
    return p1.second > p2.second;
}
int LeastTimeToComplete(const std::vector<char>& tasks, int n) {
    int all_time = 0, idle_time = 0;
    unordered_map<char, int> mp;
    for(char c: tasks)
        mp[c]++;
    priority_queue<int> pq;
    for(auto i: mp)
        pq.push(i.second);
    while(!pq.empty()) {
        int time = 0;
        vector<int> tmp;
        for(int i=0; i<=n; i++) {
            if(!pq.empty()) {
                tmp.push_back(pq.top() - 1);
                pq.pop();
                time++;
            }
        }
        for(int count: tmp) {
            if(count > 0)
                pq.push(count);
        }
        all_time += time;
        idle_time += pq.empty() ? 0 : n + 1 - time;
    }
    return all_time + idle_time;
}

int LeastTimeToComplete2(vector<char>& tasks, int n) {
    unordered_map<char, int> mp;
    for(char c: tasks)
        mp[c]++;
    vector<pair<char,int>> v(mp.begin(), mp.end());
    sort(v.begin(), v.end(), [] (pair<char, int> p1, pair<char, int> p2) {
        return p1.second < p2.second;
    });
    int max_freq = v.back().second - 1;
    v.pop_back();

    int idle_time = (max_freq - 1)*n;

    while(!v.empty() && idle_time > 0) {
        idle_time -= min(max_freq - 1, v.back().second);
        v.pop_back();
    }

    idle_time = max(0, idle_time);
    return tasks.size() + idle_time;
}

int main() {
    vector<char> tasks = {'A', 'A', 'B', 'B'};
    int n = 2;
    cout<<LeastTimeToComplete(tasks, n)<<endl;
    return 0;
}