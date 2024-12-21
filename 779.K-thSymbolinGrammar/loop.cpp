class Solution {
public:
  int kthGrammar(int n, int k) {
    // 最上位は0から始まる
    int bit = 0;
    int target_index = k;
    int num_row = n;

    while (num_row > 1) {
      int half_row_size = pow(2, num_row - 1) / 2;
      if (target_index > half_row_size) {
        target_index -= half_row_size;
        bit = !bit;
      }
      num_row--;
    }

    return bit;
  }
};
