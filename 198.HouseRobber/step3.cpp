class Solution {
public:
  int rob(vector<int>& nums) {
    if (nums.size() == 1) {
      return nums[0];
    }

    int second_previous_max_money = nums[0];
    int previous_max_money = max(nums[0], nums[1]);

    for (int i = 2; i < nums.size(); i++) {
      int temp = previous_max_money;
      previous_max_money = max(previous_max_money, second_previous_max_money + nums[i]);
      second_previous_max_money = temp;
    }

    return previous_max_money;
  }
};
