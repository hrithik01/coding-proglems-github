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

void traverseArray(vector<int> &arr)
{
    for(int i=0; i<arr.size(); i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void setZeros(vector<vector<int>> &matrix)
{
	int n = matrix.size();
	int m = matrix[0].size();
	vector<bool> rows(n, 1);
	vector<bool> cols(m, 1);
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(matrix[i][j]==0) {
				rows[i] = 0;
				cols[j] = 0;
			}
		}
	}
	for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(rows[i]==0 || cols[j]==0) matrix[i][j] = 0;
        }
    }
}

void sort012(int arr[], int n)
{
   int zero = 0, one = 0, two = 0;
   for(int i=0; i<n; i++) {
      arr[i] == 0 ? zero++ : arr[i]==1 ? one++ : two++;
   }
   for(int i=0; i<n; i++) {
      if(zero!=0 && zero--) arr[i] = 0;
      else if(one!=0 && one--) arr[i] = 1;
      else arr[i] = 2;
   }
}

// Dutch national flag algorithm
void sort012Eff(int arr[], int n)
{
    int zero = 0, one = 0, two = n-1;
    while(one <= two) {
        switch(arr[one]) {
            case 0:
                swap(arr[zero++], arr[one++]);
                break;
            case 1:
                one++;
                break;
            case 2:
                swap(arr[one], arr[two--]);
                break;
        }
    }
}

vector<int> primeNumbersTillN(int n)
{
    vector<int> primes;
    vector<bool> isPrime(n+1, 1);
    isPrime[0] = isPrime[1] = 0;
    for(int i=2; i*i<=n; i++) {
        if(isPrime[i]) {
            for(int j=i*i; j<=n; j+=i) {
                isPrime[j] = 0;
            }
        }
    }
    for(int i=2; i<=n; i++) {
        if(isPrime[i]) primes.push_back(i);
    }
    return primes;
}

int ncr(int n, int r) {
    // striver pascals, 10/1 * 9/2 * 8/3 for 10C3
    int x = min(r, n-r), res = 1;
    for(int i=0; i<x; i++) {
        res *= (n-i);
        res /= (i+1);
    }
    return res;
}

int main () {
    cout<<"Hello From Hrithik \n";
    // vector<vector<int>> matrix = {{1,1,1},{1,0,0},{1,1,1}};
    // setZeros(matrix);
    // for(int i=0; i<matrix.size(); i++) {
    //     traverseArray(matrix[i]);
    // }
    // int arr[] = {0,1,2,0,1,2};
    // int n = sizeof(arr)/sizeof(arr[0]);
    // sort012Eff(arr, n);

    // // Convert array to vector
    // std::vector<int> vec(arr, arr + n);  
    // traverseArray(vec);
    cout<<ncr(10,3)<<endl;
    return 0;
}