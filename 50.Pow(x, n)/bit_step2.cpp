class Solution {
public:
  double myPow(double x, int n) {
    int64_t num = n;
    if (num < 0) {
      num = -num;
      x = 1.0 / x;
    }

    double powered = 1.0;

    while (num) {
      // 奇数の場合の処理
      if (num & 1) {
        powered *= x;
      }
      x *= x;
      // numを半分に
      num >>= 1;
    }
    return powered;
  }
};
