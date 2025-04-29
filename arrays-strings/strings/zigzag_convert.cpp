#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<char>> convert(string s, int nr) {
    if (nr == 1) return { {s[0]} };
    int n = s.size();
    // Calculate number of columns more efficiently
    int chars_in_cycle = 2 * nr - 2;  // Number of characters in a complete cycle
    if (chars_in_cycle == 0) chars_in_cycle = 1;  // Handle the nr=1 case
    
    int full_cycles = n / chars_in_cycle;
    int remaining_chars = n % chars_in_cycle;
    
    // Each full cycle contributes (nr-1) columns
    int nc = full_cycles * (nr - 1);
    
    // Add columns for the remaining characters
    if (remaining_chars > 0) {
        nc += (remaining_chars <= nr) ? 1 : 1 + (remaining_chars - nr);
    }
    vector<vector<char>> zigzag(nr, vector<char>(nc, ' '));
    int i = 0, j = 0;
    bool down = true;
    for (int k = 0; k < s.size(); k++) {
        zigzag[i][j] = s[k];
        if (down) {
            i++;
            if (i == nr) {
                i = nr - 2;
                j++;
                down = false;
            }
        } else {
            i--;
            if (i == -1) {
                i = 1;
                down = true;
            } else {
                j++;
            }
        }
    }
    return zigzag;
    // string ans = "";
    // for (int i = 0; i < nr; i++) {
    //     for (int j = 0; j < nc; j++) {
    //         if (zigzag[i][j] != ' ') {
    //             ans += zigzag[i][j];
    //         }
    //     }
    // }
    // return ans;
}

void print2DVector(const vector<vector<char>>& vec) {
    for (const auto& row : vec) {
        for (char c : row) {
            cout << c << " ";
        }
        cout << endl;
    }
}

int main() {
    string s = "PAYPALISHIRING";
    int nr = 4;
    vector<vector<char>> zigzag = convert(s, nr);

    print2DVector(zigzag);

    string result = "";

    for (int i = 0; i < nr; i++) {
        for (int j = 0; j < zigzag[i].size(); j++) {
            if (zigzag[i][j] != ' ') {
                result += zigzag[i][j];
            }
        }
    }

    // Print the zigzag pattern


    cout << "Zigzag conversion of " << s << " with " << nr << " rows is: " << result << endl;
    return 0;
}