#include <iostream>

using namespace std;

string int2binary(int n) {
    string ans = "";
    while(n) {
        ans = n%2 ? "1" + ans : "0" + ans;
        n /= 2;
    }
    return ans;
}

/*
You are given a number ‘NUM’, return the maximum distance between any two adjacent 1s
 in the binary representation of 'NUM'. (adjacent 1s have no 1 between them)
*/
int binaryGap(int num) {
    int ans=0, currC = -1;
    while(num) {
        if(num%2) {
            if(currC != -1) ans = max(ans, currC);
            currC = 1;
        } else if(currC!=-1) currC++;
        num /= 2;
    }
    return ans;
}

int main() {
    int n = 19;
    cout << int2binary(n) << endl;
    return 0;
}