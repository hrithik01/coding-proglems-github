/*
Given a string, find the index of the first occurrence of a substring with k unique characters. If no such window exists, return -1.
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int unique_window_10chars(string str) {
    bool arr[26] = {false};
    int l=0, r=9, n=str.size(), unique=0;
    while(r<n && r>=l) {
        int ridx = str[r]-'a';
        if(arr[ridx]) {
            l = r+1;
            r = l+9;
            fill(arr, arr+26, false);
            unique = 0;
        } else {
            arr[ridx] = true;
            unique++;
            if(unique==10) {
                return l;
            }
            r--;
        }
    }
    return r>=n ? -1 : l;
}

int getLengthofLongestSubstrWithKuniqueChars(string s, int k) {
    int l=0, r=0, unique = 0, maxC=0, n=s.size();
    int arr[26] = {0};
    while(r<n && l<=r) {
        int ridx = s[r] - 'a';
        if(!arr[ridx]){
            unique++;
        }
        arr[ridx]++;
        while(unique>k) {
            int lidx = s[l]-'a';
            arr[lidx]--;
            if(!arr[lidx]) unique--;
            l++;
        }
        maxC = max(maxC, r-l+1);
        r++;
    }
    return maxC;
}

int main() {
    string str = "abcadefaghiabcdefghijklmnopqrstuvwxyyzzz";
    cout << unique_window_10chars(str) << endl;
    cout << getLengthofLongestSubstrWithKuniqueChars("abchiiijkkkklmnopqrstuvwxyyzzz", 3) << endl;
    return 0;
}