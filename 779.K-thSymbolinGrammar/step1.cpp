class Solution {
public:
  int kthGrammar(int n, int k) {
    if (k == 1) {
      return 0;
    }

    int half_row_size = pow(2, n - 1) / 2;
    if (k <= half_row_size) {
      return kthGrammar(n - 1, k);
    } else {
      return !kthGrammar(n - 1, k - half_row_size);
    }
  }
};
