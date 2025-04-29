#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
 * Time Complexity:
 * Average and Worst Case: O(n + m) where n is the length of the string and m is the length of the pattern
 * - The createPiTable function takes O(m) time
 * - The main KMP algorithm takes O(n) time as each character in the string is examined at most once
 *
 * Space Complexity: O(m) for storing the pi table (prefix function)
 */

// 0 1 2 3 4 5
// - a b a b d
// 0 0 0 1 2 0
vector<int> createPiTable(string pat, int m) {
    vector<int> pi(m + 1, 0);
    int j=0, i=2;
    while(i <= m) {
        while(j <= m && pat[j+1] == pat[i])
            pi[i++] = ++j;
        j = 0;
        i++;
    }
    return pi;
}

int kmp(string str, string pat) {
    int n = str.length(), m = pat.length();
    pat = ' ' + pat; // 1-based indexing
    vector<int> pi = createPiTable(pat, m);
    int j = 0;
    for(int i=0; i<n; i++) {
        if(pat[j+1] != str[i]) {
            while(j != 0 && pat[j+1] != str[i])
                j = pi[j];
        }
        j++;
        if(j == m) return i - m + 1;
    }
    return -1;
  }

int main() {
    string String = "aaaabb";
    string Pattern = "aab";
    int index = kmp(String, Pattern);
    if(index != -1)
        cout << "Pattern found at index: " << index << endl;
    else
        cout << "Pattern not found" << endl;
    cout << endl;
    return 0;
}