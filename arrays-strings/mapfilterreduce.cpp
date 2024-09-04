#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void printArray(const vector<int>& arr) {
    for (const auto& x : arr) {
        cout << x << endl;
    }
}

vector<int> map(const vector<int>& arr, int(*func)(int)) {
    vector<int> result;
    transform(arr.begin(), arr.end(), back_inserter(result), func);
    return result;
}

vector<int> filter(const vector<int>& arr, bool(*func)(int)) {
    vector<int> result;
    copy_if(arr.begin(), arr.end(), back_inserter(result), func);
    return result;
}

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5};

    auto squares = map(numbers, [](int x) { return x * x; });
    printArray(squares);

    auto doubles = map(numbers, [](int x) { return 2 * x; });
    printArray(doubles);

    auto evens = filter(numbers, [](int x) { return x % 2 == 0; });
    printArray(evens);

    int sum = accumulate(numbers.begin(), numbers.end(), 0);
    cout << "Sum of numbers -: " << sum << endl;
    printArray({sum});

    return 0;
}

/*
The copy_if function is a standard library function in C++ that copies elements from a range to another range if they satisfy a certain condition. It's part of the <algorithm> library.

Here's a breakdown of the function call you provided:

copy_if(arr.begin(), arr.end(), back_inserter(result), func);

arr.begin(), arr.end(): These are the beginning and end iterators of the range from which elements will be copied. In this case, it's the entire arr container.

back_inserter(result): This is the destination where the copied elements will be inserted. back_inserter is a special output iterator that appends elements to the end of the result container.

func: This is the unary predicate which returns true for the required elements. Only the elements for which this function returns true are copied.

So, this line of code is copying elements from arr to result if they satisfy the condition specified by func.
*/

/*
transform, accumulate, and back_inserter are all functions provided by the C++ Standard Library.

transform: This function applies a given function to a range and stores the result in another range, beginning at the specified location. It's part of the <algorithm> library. In your code, it's used to apply a function to each element of the arr vector and store the result in the result vector.

transform(arr.begin(), arr.end(), back_inserter(result), func);

;

accumulate: This function is used to accumulate values in a container, it's part of the <numeric> library. It calculates the sum of the range [first, last) and the initial value init. In your code, it's used to calculate the sum of all elements in the numbers vector.

int sum = accumulate(numbers.begin(), numbers.end(), 0);


back_inserter: This is a function that returns a back insert iterator for the container. It's part of the <iterator> library. It's used to insert elements at the end of the container. In your code, it's used to insert the result of the transform and copy_if operations at the end of the result vector.
back_inserter(result)

*/