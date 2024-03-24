#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int countTheDigits(int n) {
    int ans = 0;
    while(n) {
        n = n/10;
        ans++;
    }
    return ans;
}

int countTheDigits2(int n) {
    return floor(log10(n)+1);
}

int countTheDigits3(int n) {
    return to_string(n).size();
}

string int32BinaryStr(long n) {
    string str = "";
    for(int i=31; i>=0; i--) {
        int temp = n>>i;
        if(temp&1)
            str += "1";
        else
            str += "0";
    }
    return str;
}

long reverseBits(long n) {
    string strN = int32BinaryStr(n);
    reverse(strN.begin(), strN.end());
    long ans = 0;
    for(int i=0; i<strN.size(); i++) {
        ans = ans*2 +(strN[i] - '0');
    }
    return ans;
}

// This function does the same thing but it reverses the bits of n by shifting them into result one by one, from least significant to most significant. This avoids the need to convert n to a string and then convert the reversed string back to an integer.
uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    for (int i = 0; i < 32; i++) {
        result <<= 1;
        if (n & 1) {
            result++;
        }
        n >>= 1;
    }
    return result;
}

int reverseNumber(int n) {
    long ans = 0;
    int sign = n<0 ? -1 : 1;
    n = abs(n);
    while(n) {
        int k = n%10;
        n /= 10;
        ans = ans*10 + k;
        if (ans > INT_MAX || ans < INT_MIN)
            return 0;
    }
    return sign * ans;
}

bool checkPalindrome(int n) {
    int rev = 0;
    // 12321, rev will become 123 and n will be 12
    while(n>rev) {
        rev = rev*10 + n%10;
        n /= 10;
    }
    // if odd then eliminate the middle one
    return n == rev || n == rev/10;
}

int gcd(int m, int n) {
    return n==0?m:gcd(n,m%n);
}

bool checkArmstrong(int n){
    int x = n;
    double temp = 0;
    int numDigits = floor(log10(n) + 1);
    while(x) {
        temp = temp + pow(x % 10, numDigits);
        x /= 10;
    }
    return temp == n;
}

bool isPerfectSqr(int n) { 
    int k = sqrt(n); 
    return k*k == n;
 }

 // Less efficient approach of calculating till sqrt(n) for 1
int sumOfDivisors(int n) { 
    int res = 0; 
    for(int i=1; i*i<n; i++) { 
        if (n % i == 0) { 
            res = res + (i + n/i); 
        } 
    } 
    return isPerfectSqr(n) ? res + sqrt(n): res;
} 
// adding for each indiviadual number and not taking benefit of pattern
int sumOfAllDivisors(int n){ 
    int ans = 0; 
    for(int i=1; i<=n; i++) { 
        ans += sumOfDivisors(i); 
    } 
    return ans; 
}

// Efficient approach for n =6, 1, 1,2, 1,3, 1,2,4, 1,5, 1,2,3,6
int sumOfAllDivisorsEfficient(int n) {
    int totalSum = 0;
    for (int i = 1; i <= n; i++) {
        totalSum += i * (n / i);
    }
    return totalSum;
}

void SieveOfEratosthenes(int n) {
    vector<bool> prime(n+1, true);
    prime[0] = prime[1] = false;
    for (int p = 2; p*p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p*p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++)
       if (prime[p])
          cout << p << " ";
}

bool isPrime(int n) {
    if(n==2) return true;
    if(n<2 || n%2==0) return false;
    for(int i=3; i*i<=n; i+=2) {
        if(n%i==0) return false;
    }
    return true;
}

int main () {
    int n;
    // uint32_t n;
    cout<<"Enter input _: ";
    cin>>n;
    int m;
    cin>>m;
    cout<<"Running brain \n";\
    // cout<<reverseBits(n)<<"\n";
    // cout<<checkPalindrome(n)<<endl;
    cout<<gcd(m,n)<<"\n";
    return 0;
}
