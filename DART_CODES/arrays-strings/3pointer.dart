// DART_CODES/arrays-strings/3pointer.dart
// Converted from C++
// Logic and comments preserved
/*
You are given three arrays X, Y and Z of size A,B and C respectively. Also, all three arrays are sorted in non-decreasing order. Find i, j, k such that : 0 <= i < A, 0 <= j < B, 0 <= k < C and max(abs(X[i] - Y[j]), abs(Y[j] - Z[k]), abs(Z[k] - X[i])) is minimized. Your task is to return the minimum of all the max(abs(X[i] - Y[j]), abs(Y[j] - Z[k]), abs(Z[k] - X[i]))
*/

int threePointer(List<int> X, List<int> Y, List<int> Z) {
  int i = 0, j = 0, k = 0;
  int minMaxDiff = 1 << 30;
  while (i < X.length && j < Y.length && k < Z.length) {
    int maxDiff = [
      (X[i] - Y[j]).abs(),
      (Y[j] - Z[k]).abs(),
      (Z[k] - X[i]).abs()
    ].reduce((a, b) => a > b ? a : b);
    minMaxDiff = minMaxDiff < maxDiff ? minMaxDiff : maxDiff;
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

void main() {
  List<int> X = [1, 4, 10];
  List<int> Y = [2, 15, 20];
  List<int> Z = [10, 12];
  print("Minimum of the maximum absolute differences: ${threePointer(X, Y, Z)}");
}
