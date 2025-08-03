class Solution {
public:
  int maxArea(vector<int>& heights) {
    int max_amount_water = -1;
    for (int i = 0; i < heights.size(); i++) {
      for (int j = 0; j < heights.size(); j++) {
        int width = j - i;
        int height = min(heights[i], heights[j]);
        max_amount_water = max(max_amount_water, height * width);
      }
    }
    return max_amount_water;
  }
};
