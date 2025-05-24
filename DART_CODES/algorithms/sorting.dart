// DART_CODES/algorithms/sorting.dart
// Converted from C++
// Logic and comments preserved

void merge(List<int> arr, int l, int m, int r) {
  List<int> temp = [];
  int i = l, j = m + 1;
  while (i <= m && j <= r) {
    if (arr[i] <= arr[j]) {
      temp.add(arr[i++]);
    } else {
      temp.add(arr[j++]);
    }
  }
  while (i <= m) {
    temp.add(arr[i++]);
  }
  while (j <= r) {
    temp.add(arr[j++]);
  }
  for (int k = l; k <= r; k++) {
    arr[k] = temp[k - l];
  }
}

void mergeSort(List<int> arr, int l, int r) {
  if (l < r) {
    int m = l + ((r - l) ~/ 2);
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}

int partition(List<int> arr, int low, int high) {
  int pivot = arr[high];
  int i = low - 1;
  for (int j = low; j < high; j++) {
    if (arr[j] < pivot) {
      i++;
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  i++;
  int temp = arr[i];
  arr[i] = arr[high];
  arr[high] = temp;
  return i;
}

void quickSort(List<int> arr, int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}
