class Solution {
public:
  double myPow(double x, int n) {

    if (n < 0) {
      return 1 / Pow(x, -(long)n);
    } else {
      return Pow(x, n);
    }
  }

private:
  double Pow(double x, long num) {
    double powered = 1.0;
    if (num == 0) {
      return powered;
    }

    while (num > 0) {
      if (num % 2 != 0) {
        powered *= x;
      }
      x *= x;
      num /= 2;
    }

    return powered;
  }
};
