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

vector<int> nextPermutation(vector<int> &p, int n)
{
    if (n==1) return p;
    int i = n-2;
    while(i>=0 && p[i] >= p[i+1] ) 
        i--;
    if(i>=0) {
        int j=n-1;
        int justGreater = i+1;
        while(j>i) {
            if(p[j]>p[i])
                justGreater = p[j]<p[justGreater] ? j : justGreater;
            j--;
        }
        swap(p[i], p[justGreater]);
    }
    reverse(p.begin() + i +1, p.end());
    return p;
}

int main () {
    cout<<"Hello From Hrithik \n";
    vector<int> p = {1,3,2};
    int n = p.size();
    p = nextPermutation(p, n);
    for(int i=0; i<n; i++) {
        cout<<p[i]<<" ";
    }
    cout<<endl;
    return 0;
}
