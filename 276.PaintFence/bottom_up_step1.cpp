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
    vector<int> paint_ways_so_far(n + 1);
    paint_ways_so_far[1] = k;
    paint_ways_so_far[2] = k * k;
    for (int i = 3; i <= n; i++) {
      int same_paint = paint_ways_so_far[i - 2] * (k - 1);
      int diff_paint = paint_ways_so_far[i - 1] * (k - 1);
      paint_ways_so_far[i] = same_paint + diff_paint;
    }
    return paint_ways_so_far.back();
  }
};
