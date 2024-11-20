// Given a long string , find the starting index of the window where all 10 characters are unique
#include <iostream>
#include <string>

using namespace std;

void setArrFalse(bool* arr) {
    for(int i=0; i<26; i++) {
        arr[i] = false;
    }
}

int fn(string s, int n) {
    if(n < 10) {
        return -1;
    }
    int l=0, r=9, unique=0;
    bool arr[26] = {false};

    while(r<n) {
        char c = s[r];
        if(arr[c-'A'] == false) {
            arr[c-'A'] = true;
            unique++;
            r--;
        } else {
            setArrFalse(arr);
            l++;
            r = l+9;
            unique = 0;
            continue;
        }
        if(unique == 10) {
            return l;
        }
    }
    return -1;
}

int main() {
    string s1 = "AAABCDEFGHIKLMN";
    cout << fn(s1, s1.size()) << endl;
    string s2 = "ASDFGHHHHJKLGFDSAQWE";
    cout << fn(s2, s2.size()) << endl;
    return 0;
}