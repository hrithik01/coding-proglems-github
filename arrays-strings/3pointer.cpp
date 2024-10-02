/*
You are given three arrays X, Y and Z of size A,B and C respectively.Also, all three arrays are sorted in non-decreasing order. Find i, j, k such that : 0 <= i < A, 0 <= j < B, 0 <= k < C and max(abs(X[i] - Y[j]), abs(Y[j] - Z[k]), abs(Z[k] - X[i])) is minimized. Your task is to return the minimum of all the max(abs(X[i] - Y[j]), abs(Y[j] - Z[k]), abs(Z[k] - X[i]))
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int threePointer(vector<int>& X, vector<int>& Y, vector<int>& Z) {
    int i = 0, j = 0, k = 0;
    int minMaxDiff = INT_MAX;

    while (i < X.size() && j < Y.size() && k < Z.size()) {
        int maxDiff = max({abs(X[i] - Y[j]), abs(Y[j] - Z[k]), abs(Z[k] - X[i])});
        minMaxDiff = min(minMaxDiff, maxDiff);

        // Move the pointer that points to the smallest element
        if (X[i] <= Y[j] && X[i] <= Z[k]) {
            i++;
        } else if (Y[j] <= X[i] && Y[j] <= Z[k]) {
            j++;
        } else {
            k++;
        }
    }

    return minMaxDiff;
}

int main() {
    vector<int> X = {1, 4, 10};
    vector<int> Y = {2, 15, 20};
    vector<int> Z = {10, 12};

    cout << "Minimum of the maximum absolute differences: " << threePointer(X, Y, Z) << endl;

    return 0;
}