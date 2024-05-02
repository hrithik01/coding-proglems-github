// A majority element is an element that makes up more than half of the items in an array.
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int majorityElementOptimized(vector<int> arr) {
    int count = 0;
    int res = -1;
    for(int i=0; i<arr.size(); i++) {
        if(count == 0) {
            res = arr[i];
            count = 1;
        } else if(arr[i] == res) {
            count++;
        } else {
            count--;
        }
    }
    count = 0;
    for(int i=0; i<arr.size(); i++) {
        if(arr[i] == res) {
            count++;
        }
    }
    if(count > arr.size()/2) {
        return res;
    }
    return -1;
}

int main () {
    vector<int> arr = {1, 2, 3, 4, 5, 5, 5, 5, 5};
    map<int, int> m;
    for (int i = 0; i < arr.size(); i++) {
        m[arr[i]]++;
    }
    for (auto i = m.begin(); i != m.end(); i++) {
        if (i->second > arr.size() / 2) {
            cout << i->first << endl;
        }
    }
    cout << majorityElementOptimized(arr) << endl;
    return 0;
}