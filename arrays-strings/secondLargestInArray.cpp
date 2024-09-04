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

int secondLargestInArray(vector<int> arr) {
    int res = -1;
    pair<int, int> p (0, -1);
    for(int i=1; i<arr.size(); i++) {
        if(arr[i] > arr[p.first]) {
            p.second = p.first;
            p.first = i;
        } else if(arr[i] != arr[p.first]) {
            if(p.second == -1 || arr[i] > arr[p.second]) {
                p.second = i;
            }
        }
    }
    return p.second == -1 ? -1 : arr[p.second];
}

int main () {
    vector<int> arr = {5,5,5,5,5,4,3};
    cout<<"Second largest element is -: "<<secondLargestInArray(arr)<<endl;
    return 0;
}