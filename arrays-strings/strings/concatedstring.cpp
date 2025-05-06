#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

/*
30. Substring with Concatenation of All Words
You are given a string s and an array of strings words. All the strings of words are of the same length.
A concatenated string is a string that exactly contains all the strings of any permutation of words concatenated.
For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated string because it is not the concatenation of any permutation of words.
Return an array of the starting indices of all the concatenated substrings in s. You can return the answer in any order.

Example 1:
Input: s = "barfoothefoobarman", words = ["foo","bar"]
Output: [0,9]

Explanation:
The substring starting at 0 is "barfoo". It is the concatenation of ["bar","foo"] which is a permutation of words.
The substring starting at 9 is "foobar". It is the concatenation of ["foo","bar"] which is a permutation of words.

Example 2:
Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
Output: []
Explanation:
There is no concatenated substring.
*/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;
        
        int wordLength = words[0].size();
        int numWords = words.size();
        int totalLength = wordLength * numWords;
        int sLength = s.size();
        
        // If s is shorter than the concatenated length, no match is possible
        if (sLength < totalLength) return result;
        
        // Count frequency of each word in words array
        unordered_map<string, int> wordCount;
        for (const string& word : words) {
            wordCount[word]++;
        }
        
        // For each possible starting position of the first word
        for (int i = 0; i < wordLength; i++) {
            // Use sliding window approach
            int left = i; // Left boundary of current window
            int right = i; // Right boundary of current window
            int count = 0; // Count of valid words in current window
            
            // Track words and their counts in the current window
            unordered_map<string, int> windowCount;
            
            // Slide window through the string
            while (right + wordLength <= sLength) {
                // Get the next word
                string word = s.substr(right, wordLength);
                right += wordLength;
                
                // If it's not a valid word, reset the window
                if (wordCount.find(word) == wordCount.end()) {
                    windowCount.clear();
                    count = 0;
                    left = right;
                    continue;
                }
                
                // Add this word to our window
                windowCount[word]++;
                count++;
                
                // If we have too many occurrences of this word, shrink the window from left
                while (windowCount[word] > wordCount[word]) {
                    string leftWord = s.substr(left, wordLength);
                    windowCount[leftWord]--;
                    count--;
                    left += wordLength;
                }
                
                // Check if we have found a valid concatenation
                if (count == numWords) {
                    result.push_back(left);
                    
                    // Move the window by one word to find overlapping matches
                    string leftWord = s.substr(left, wordLength);
                    windowCount[leftWord]--;
                    count--;
                    left += wordLength;
                }
            }
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    string s = "barfoothefoobarman";
    vector<string> words = {"foo", "bar"};
    
    vector<int> result = solution.findSubstring(s, words);
    
    cout << "Starting indices of all concatenated substrings: ";
    for (int index : result) {
        cout << index << " ";
    }
    cout << endl;
    
    return 0;
}
// Output: Starting indices of all concatenated substrings: 0 9
// Time and Space Complexity: O(N * M) where N is the length of s and M is the number of words