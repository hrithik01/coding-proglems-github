#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        // O(N) time and O(1) space complexity in one loop
        int romanToInt(string s) {
            unordered_map<char, int> romanMap = {
                {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
                {'C', 100}, {'D', 500}, {'M', 1000}
            };
            int total = 0;
            int prevValue = 0;
            for (char c : s) {
                int currValue = romanMap[c];
                total += currValue;
                if (prevValue < currValue) {
                    total -= 2 * prevValue; // Adjust for the previous value
                }
                prevValue = currValue;
            }
            return total;
        }

        string intToRoman(int num) {
            string result;
            vector<pair<int, string>> romanNumerals = {
                {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
                {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
                {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"},
                {1, "I"}
            };
            for (auto& pair : romanNumerals) {
                while (num >= pair.first) {
                    result += pair.second;
                    num -= pair.first;
                }
            }
            return result;
        }

        void printVector(vector<int>& nums) {
            cout << "Vector: "<< endl;
            for (int i = 0; i < nums.size(); i++) {
                cout << nums[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    Solution s;
    string roman = "MCMXCIV"; // Example Roman numeral
    int result = s.romanToInt(roman);
    cout << "The integer value of the Roman numeral " << roman << " is: " << result << endl;

    int num = 1994; // Example integer
    string romanResult = s.intToRoman(num);
    cout << "The Roman numeral representation of the integer " << num << " is: " << romanResult << endl;
    return 0;
}