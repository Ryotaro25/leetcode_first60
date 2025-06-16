class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    if (nums.size() == 0) {
      return 0;
    }
    vector<int> partial_sums(nums.size());
    partial_sums[0] = nums[0];

    int max_sum = partial_sums[0];
    for (int i = 1; i < nums.size(); i++) {
      partial_sums[i] = max(nums[i], partial_sums[i - 1] + nums[i]);
      max_sum = max(max_sum, partial_sums[i]);
    }

    return max_sum;
  }
};
