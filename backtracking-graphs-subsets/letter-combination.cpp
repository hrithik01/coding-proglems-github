#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int usefulSize(string num) {
    int n = num.size();
    for (int i = 0; i < n; i++) {
        if (num[i] == '1' || num[i] == '0') {
            n--;
        }
    }
    return n;
}

string vector2string(vector<char>& v) {
    string s = "";
    for (char c : v) {
        s += c;
    }
    return s;
}

void backtrack(vector<string>& res, vector<char>& curr, unordered_map<int, vector<char>>& mp, vector<int>& digits_int, int curr_index, int n) {
    if(curr.size() == n) {
        res.push_back(vector2string(curr));
        return;
    }
    for(char c: mp[digits_int[curr_index]]) {
        curr.push_back(c);
        backtrack(res, curr, mp, digits_int, curr_index + 1, n);
        curr.pop_back();
    }
}

vector<string> LetterCombinations(string digits)
{
    unordered_map<int, vector<char>> mp;
    vector<string> res;
    int n = usefulSize(digits);
    if (n == 0)
    {
        return res;
    }
    vector<int> digits_int;
    for (char c : digits)
    {
        if(c != '1' && c != '0')
            digits_int.push_back(c - '0');
    }
    mp[1] = {};
    mp[2] = {'a', 'b', 'c'};
    mp[3] = {'d', 'e', 'f'};
    mp[4] = {'g', 'h', 'i'};
    mp[5] = {'j', 'k', 'l'};
    mp[6] = {'m', 'n', 'o'};
    mp[7] = {'p', 'q', 'r', 's'};
    mp[8] = {'t', 'u', 'v'};
    mp[9] = {'w', 'x', 'y', 'z'};
    vector<char> curr;
    backtrack(res, curr, mp, digits_int, 0, n);
    return res;
}


int main() {
    string n = "213";
    vector<string> result = LetterCombinations(n);
    for (string s : result) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}