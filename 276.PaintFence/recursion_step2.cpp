class Solution {
public:
    int numWays(int n, int k) {
      if (n == 0) {
        return 0;
      }
      // initialize with impossible value
      vector<int> paint_ways_so_far(n + 1, -1);
      return PaintWays(paint_ways_so_far, n, k);
    }

private:
  int PaintWays(vector<int>& paint_ways_so_far, int num_fence, int num_color) {
    if (paint_ways_so_far[num_fence] != -1) {
      return paint_ways_so_far[num_fence];
    }
    if (num_fence == 1) {
      return num_color;
    }
    if (num_fence == 2) {
      return num_color * num_color;
    }
    int diff_paint = (num_color - 1) * PaintWays(paint_ways_so_far, num_fence - 1, num_color);
    int same_paint = (num_color - 1) * PaintWays(paint_ways_so_far, num_fence - 2, num_color);
    paint_ways_so_far[num_fence] = diff_paint + same_paint;
    return diff_paint + same_paint; 
  }
};
