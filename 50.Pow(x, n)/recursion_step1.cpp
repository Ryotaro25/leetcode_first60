class Solution {
public:
  double myPow(double x, int n) {
    if (n >= 0) {
      return MyPow(x, n);
    } else {
      return 1.0 / MyPow(x, -static_cast<int64_t>(n));
    }
  }

private:
  double MyPow(double base, int64_t power) {
    if (power == 0) {
      return 1.0;
    }
    double half = MyPow(base, power / 2);
    if (power % 2 == 0) {
      return half * half;
    } else {
      return half * half * base;
    }
  }
};
