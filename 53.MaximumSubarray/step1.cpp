class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    vector<int> partial_sums(nums.size());
    partial_sums[0] = nums[0];

    for (int i = 1; i < nums.size(); i++) {
      partial_sums[i] = max(nums[i], partial_sums[i - 1] + nums[i]);
    }

    sort(partial_sums.rbegin(), partial_sums.rend());
    return partial_sums[0];
  }
};
