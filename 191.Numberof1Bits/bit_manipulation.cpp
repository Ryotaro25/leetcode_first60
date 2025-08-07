class Solution {
public:
  int hammingWeight(int n) {
    int num_bits = 0;
    while (n != 0) {
      num_bits += 1;
      // nと(n-1)のビットごとのAND演算を行うことで、
      // nの最も右側にある1のビットを0に反転させる
      n &= (n - 1);
    }
    return num_bits;
  }
};
