#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int l, int m, int r) {
    vector<int> temp;
    int i = l, j = m + 1;
    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }
    while (i <= m) {
        temp.push_back(arr[i++]);
    }
    while (j <= r) {
        temp.push_back(arr[j++]);
    }
    for (int i = l; i <= r; i++) {
        arr[i] = temp[i - l];
    }
}

void merge_sort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    i++;
    swap(arr[i], arr[high]);
    return i;
}

void quick_sort(vector<int>& arr, int low, int high) {
    if(low < high) {
        int partition_index = partition(arr, low, high);
        quick_sort(arr, low, partition_index - 1);
        quick_sort(arr, partition_index + 1, high);
    }
}

int main() {
    vector<int> arr = {5, 4, 3, 2, 1};

    // merge_sort(arr, 0, arr.size() - 1);
    // quick_sort(arr, 0, arr.size() - 1);

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}