class Solution {
public:
  int rob(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }
    if (nums.size() == 1) {
      return nums[0];
    }
    if (nums.size() == 2) {
      return max(nums[0], nums[1]);
    }

    vector<int> max_money_with_first(nums.size() - 1);
    max_money_with_first[0] = nums[0];
    max_money_with_first[1] = max(nums[0], nums[1]);
    for (int i = 2; i < nums.size() - 1; i++) {
      max_money_with_first[i] = max(max_money_with_first[i - 2] + nums[i], max_money_with_first[i - 1]);
    }

    vector<int> max_money_with_second(nums.size());
    max_money_with_second[1] = nums[1];
    max_money_with_second[2] = max(nums[1], nums[2]);
    for (int i = 2; i < nums.size(); i++) {
      max_money_with_second[i] = max(max_money_with_second[i - 2] + nums[i], max_money_with_second[i - 1]);
    }
    return max(max_money_with_first.back(), max_money_with_second.back());
  }
};
