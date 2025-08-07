class Solution {
public:
  int hammingWeight(int n) {
    int num_bits = 0;
    while (n > 0) {
      if (n % 2 == 1) {
        num_bits +=1;
      }
      n /= 2;
    }
    return num_bits;
  }
};
