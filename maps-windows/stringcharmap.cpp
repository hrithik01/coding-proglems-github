#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // Parse the string into words
        vector<string> words;
        stringstream ss(s);
        string word;
        
        // Extract words from input string
        while (ss >> word) {
            words.push_back(word);
        }
        
        // Check if pattern length matches words count
        if (pattern.size() != words.size()) {
            return false;
        }
        
        // Create maps for bidirectional mapping
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;
        
        // Check if the pattern matches the words
        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            string w = words[i];
            
            // If char is already mapped, check if it maps to the current word
            if (charToWord.find(c) != charToWord.end()) {
                if (charToWord[c] != w) {
                    return false; // Violation: char maps to different words
                }
            } 
            // If word is already mapped, check if it maps to the current char
            else if (wordToChar.find(w) != wordToChar.end()) {
                if (wordToChar[w] != c) {
                    return false; // Violation: word maps to different chars
                }
            } 
            // Create new mappings
            else {
                charToWord[c] = w;
                wordToChar[w] = c;
            }
        }
        
        return true;
    }
};

int main() {
    Solution solution;
    string pattern = "abba";
    string s = "dog cat cat dog";
    
    bool result = solution.wordPattern(pattern, s);
    cout << (result ? "true" : "false") << endl; // Output: true
    
    return 0;
}