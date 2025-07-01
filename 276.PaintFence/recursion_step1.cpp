class Solution {
public:
    int numWays(int n, int k) {
      if (n == 0) {
        return 0;
      }
      return PaintWays(n, k);
    }

private:
  int PaintWays(int num_fence, int num_color) {
    if (num_fence == 1) {
      return num_color;
    }
    if (num_fence == 2) {
      return num_color * num_color;
    }
    int diff_paint = (num_color - 1) * PaintWays(num_fence - 1, num_color);
    int same_paint = (num_color - 1) * PaintWays(num_fence - 2, num_color);
    return diff_paint + same_paint; 
  }
};
