#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
/**
 * @brief Justifies text to fit within a specified width.
 * 
 * This function takes a list of words and formats them into lines such that:
 * - Each line has exactly maxWidth characters
 * - Words are separated by spaces as evenly as possible
 * - Extra spaces are distributed starting from left
 * - Last line is left-justified with only one space between words and trailing spaces
 * - Lines with only one word are also left-justified with trailing spaces
 * 
 * The algorithm works by:
 * 1. Greedily fitting as many words as possible into each line
 * 2. For regular lines, calculating the space distribution to fully justify text
 * 3. Handling special cases (last line, single word) with left justification
 * 
 * @param words Vector of strings representing words to be justified
 * @param maxWidth Maximum width of each line
 * @return Vector of strings where each string is a justified line
 * 
 * @time_complexity O(n), where n is the total number of words
 *                  Each word is processed once and the space calculations are O(1) per line
 * @space_complexity O(L), where L is the total length of the output text
 *                   The space used is proportional to the justified text output
 */
{
public:


    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> ans;
        int i = 0, n = words.size();
        while (i < n)
        {
            // Start processing a new line
            string temp = "";
            int tempSz = words[i].size();
            int j = i + 1;
            // Greedily fit as many words as possible into the current line
            while (j < n && tempSz + 1 + words[j].size() <= maxWidth)
            {
                tempSz = tempSz + 1 + words[j].size();
                j++;
            }
            // Handle special cases: last line or only one word in the line
            if (i == j - 1 || j >= n)
            {
                // For last line or single word: left justify and fill trailing spaces
                temp = words[i];
                for (int k = i + 1; k < j; k++)
                {
                    temp = temp + " " + words[k];
                }
                tempSz = temp.size();
                while (tempSz < maxWidth)
                {
                    temp += " ";
                    tempSz++;
                }
            }
            else
            {
                // Handle regular lines: fully justify with even space distribution
                // Calculate total characters used by words
                int totalChars = 0;
                for (int k = i; k < j; k++)
                {
                    totalChars += words[k].size();
                }
                // Calculate spaces needed and how to distribute them
                int spaces = maxWidth - totalChars;
                int slots = j - i - 1;  // Number of gaps between words
                int evenSpace = spaces / slots;  // Equal spaces per slot
                int extra = spaces % slots;      // Extra spaces for left slots
                for (int k = i; k < j; k++)
                {
                    temp += words[k];
                    if (k < j - 1)
                    {
                        // Distribute spaces evenly with extra spaces going left
                        int spaceToAdd = evenSpace + (extra > 0 ? 1 : 0);
                        temp += string(spaceToAdd, ' ');
                        if (extra > 0)
                            extra--;
                    }
                }
            }
            ans.push_back(temp);
            i = j;  // Move to next set of words for the next line
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 16;
    vector<string> result = s.fullJustify(words, maxWidth);
    for (const string &line : result)
    {
        cout << "\"" << line << "\"" << endl;
    }
    return 0;
}