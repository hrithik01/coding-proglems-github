#include <iostream>

using namespace std;

void rec1(int i, int n) {
    if(i>n) return;
    cout<<i<<" ";
    rec1(i+1, n);
}

void rec2(int n) {
    if(n<1) return;
    rec2(n-1);
    cout<<n<<" ";
}

void sumOfNRec1(int ans, int n) {
    if(n==0) cout<<ans<<endl;
    else sumOfNRec1(ans+n, n-1);
}

int sumOfRec2(int n) {
    if(n==0) return 0;
    return n + sumOfRec2(n-1);
}

int main () {
    cout<<"Hello From Hrithik \n";
    // rec1(1, 10);
    // rec2(10);
    // cout<<endl;
    sumOfNRec1(0, 10);
    cout<<sumOfRec2(10)<<endl;
    return 0;
}

// g++ filetorun.cpp -o outputfilename      - To compile the file.
// ./outputfilename      - To run the file.
// g++ -std=c++11 filetorun.cpp -o outputfilename    - To run specific version of c++.