#include <vector>
#include <string>
#include <iostream>

using namespace std;

void generatePermutationsBackTracking(vector<string>& permutations, string word, int start) {
    if (start >= word.size()) {
        permutations.push_back(word);
        return;
    }
    for (int i = start; i < word.size(); i++) {
        swap(word[start], word[i]);
        generatePermutationsBackTracking(permutations, word, start + 1);
        swap(word[start], word[i]); // backtrack
    }
}

vector<string> permuteWordBT(string word) {
    vector<string> permutations;
    generatePermutationsBackTracking(permutations, word, 0);
    return permutations;
}

void generatePermutations(vector<string>& permutations, int start, int end) {
    if (start >= end - 1) return;
    int currentSize = permutations.size();
    for (int i = 0; i < currentSize; i++) {
        for (int j = start + 1; j < end; j++) {
            string temp = permutations[i];
            swap(temp[start], temp[j]);
            permutations.push_back(temp);
        }
    }
    generatePermutations(permutations, start + 1, end);
}

vector<string> permuteWord(string word) {
    vector<string> permutations;
    permutations.push_back(word);
    generatePermutations(permutations, 0, word.length());
    return permutations;
}

void print(vector<string>& result) {
    for (string s : result) {
        cout << s << "  ";
    }
}

int main() {
    string word = "abc";
    vector<string> result = permuteWord(word);
    print(result);
    cout << endl;
    vector<string> resultBT = permuteWordBT(word);
    print(resultBT);
    cout << endl;
    return 0;
}