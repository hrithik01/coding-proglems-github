#include <iostream>
#include <string>
#include <vector>

using namespace std;

string fb4n(int n) {
    if (n%3 == 0 && n%5 == 0) return "FizzBuzz";
    else if (n%3 == 0) return "Fizz";
    else if (n%5 == 0) return "Buzz";
    else return to_string(n);
}

int main() {
    string s = "";
    int n;
    cout<<"Enter an integer: ";
    cin>>n;
    for(int i=1; i<=n; i++) {
        s += fb4n(i);
    }
    cout<<"\n Answer string is -: "<<s<<endl;
    return 0;
}