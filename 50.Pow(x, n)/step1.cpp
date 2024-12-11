class Solution {
public:
  double myPow(double x, int n) {
    long long num = n;
    if (num < 0) {
      return 1 / Pow(x, -num);
    }
    return Pow(x, n);
  }

private:
  double Pow(double x, long long num) {
    if (num == 0) {
      return 1.0;
    }
    if (num % 2 != 0) {
      return x * Pow(x * x, (num - 1) / 2);
    }
    return Pow(x * x, num / 2);
  }
};
