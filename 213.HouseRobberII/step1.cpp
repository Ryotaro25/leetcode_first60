class Solution {
public:
  int rob(vector<int>& nums) {
    if (nums.size() == 1) {
      return nums[0];
    }
    if (nums.size() == 2) {
      return max(nums[0], nums[1]);
    }

    int second_back_max_money = nums[0];
    int one_back_max_money = max(nums[0], nums[1]);
    for (int i = 2; i < nums.size() - 1; i++) {
      int current_max = max(one_back_max_money, second_back_max_money + nums[i]);
      second_back_max_money = one_back_max_money;
      one_back_max_money = current_max;
    }
    int first_rob_max = one_back_max_money;

    second_back_max_money = nums[1];
    one_back_max_money = max(nums[1], nums[2]);
    for (int i = 3; i < nums.size(); i++) {
      int current_max = max(one_back_max_money, second_back_max_money + nums[i]);
      second_back_max_money = one_back_max_money;
      one_back_max_money = current_max;
    }

    int second_rob_max = one_back_max_money;
    return max(first_rob_max, second_rob_max);
  }
};
