class Solution {
public:
  int subarraySum(vector<int>& nums, int k) {
    if (nums.empty()) {
      return 0;
    }

    vector<int> cumulative_sum(nums.size() + 1, 0);
    for (int i = 0; i < nums.size(); i++) {
      cumulative_sum[i + 1] = cumulative_sum[i] + nums[i];
    }

    int cnt = 0;
    for (int left = 0; left < cumulative_sum.size(); left++) {
      for (int right = left + 1; right < cumulative_sum.size(); right++) {
        if (cumulative_sum[right] - cumulative_sum[left] == k) {
          cnt++;
        }
      }
    }
    return cnt;
  }
};
