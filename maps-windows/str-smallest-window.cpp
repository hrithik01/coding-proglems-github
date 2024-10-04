#include <iostream>
#include <map>
#include <string>

using namespace std;

string smallestWindow(string s, string x)
{
    int ansL=0, l=0, ans=INT_MAX, count=0;
    map<char,int> m;
    for(char c: x) m[c]++;
    for(int i=0; i<s.size(); i++) {
        char c = s[i];
        m[c]--;
        if(m[c]>=0) count++;
        while(count == x.size()) {
            if(i-l+1 < ans) {
                ans = i-l+1;
                ansL = l;
            }
            if(m[s[l]]>=0) count--;
            m[s[l]]++;
            l++;
        }
    }
    return ans == INT_MAX ? "" : s.substr(ansL, ans);
}

int main() {
    cout<<smallestWindow("this is a test string", "tist")<<endl;
    cout<<smallestWindow("geeksforgeeks", "ork")<<endl;
    cout<<smallestWindow("ADOBECODEBANC", "ABC")<<endl;
    return 0;
}