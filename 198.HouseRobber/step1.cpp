class Solution {
public:
  int rob(vector<int>& nums) {
    if (nums.size() == 1) {
      return nums[0];
    }
    vector<int> max_money_so_far(nums.size());
    max_money_so_far[0] = nums[0];
    max_money_so_far[1] = max(nums[0], nums[1]);

    for (int i = 2; i < nums.size(); i++) {
      max_money_so_far[i] = max(max_money_so_far[i -1], max_money_so_far[i -2] + nums[i]);
    }

    return max_money_so_far[nums.size() - 1];
  }
};
