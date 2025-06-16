class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }
    int max_sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      int current_sum = 0;
      for (int j = i; j < nums.size(); j++) {
        current_sum += nums[j];
        max_sum = max(max_sum, current_sum);
      }
    }
    return max_sum;
  }
};
