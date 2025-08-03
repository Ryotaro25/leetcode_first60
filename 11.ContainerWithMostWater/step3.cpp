class Solution {
public:
  int maxArea(vector<int>& heights) {
    if (heights.empty()) {
      return 0;
    }
    int left = 0;
    int right = heights.size() - 1;
    int max_amount_water = 0;
    while (left < right) {
      int height = min(heights[left], heights[right]);
      int width = right - left;
      max_amount_water = max(max_amount_water, height * width);
      if (heights[left] < heights[right]) {
        left++;
      } else {
        right--;
      }
    }
    return max_amount_water;
  }
};
