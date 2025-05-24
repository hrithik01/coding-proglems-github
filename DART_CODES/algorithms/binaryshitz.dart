// DART_CODES/algorithms/binaryshitz.dart
// Converted from C++
// Logic and comments preserved

String int2binary(int n) {
  String ans = "";
  while (n != 0) {
    ans = (n % 2 == 1 ? "1" : "0") + ans;
    n ~/= 2;
  }
  return ans;
}

/*
You are given a number 'NUM', return the maximum distance between any two adjacent 1s
in the binary representation of 'NUM'. (adjacent 1s have no 1 between them)
*/
int binaryGap(int num) {
  int ans = 0, currC = -1;
  while (num != 0) {
    if (num % 2 == 1) {
      if (currC != -1) ans = ans > currC ? ans : currC;
      currC = 1;
    } else if (currC != -1) currC++;
    num ~/= 2;
  }
  return ans;
}

void main() {
  int n = 19;
  print(int2binary(n));
}
