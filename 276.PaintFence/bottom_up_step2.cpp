class Solution {
public:
  int numWays(int n, int k) {
    if (n == 0) {
      return 0;
    }
    if (n == 1) {
      return k;
    }
    if (n == 2) {
      return k * k;
    }
    int two_previous_way = k;
    int one_previous_way = k * k;
    for (int i = 2; i < n; i++) {
      int same_paint = two_previous_way * (k - 1);
      int diff_paint = one_previous_way * (k - 1);

      two_previous_way = one_previous_way;
      one_previous_way = same_paint + diff_paint;
    }
    return one_previous_way;
  }
};
