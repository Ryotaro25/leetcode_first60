class Solution {
public:
  int rob(vector<int>& nums) {
    int num_size = nums.size();
    if (num_size == 1) {
      return nums[0];
    }
    if (num_size == 2) {
      return max(nums[0], nums[1]);
    }

    return max(RobMaxMoney(nums, 2, num_size - 1), RobMaxMoney(nums, 3, num_size));
  }

private:
  int RobMaxMoney(const vector<int>& nums, const int start_index, const int end_index) {
    int second_back_max_money = nums[start_index - 2];
    int one_back_max_money = max(nums[start_index - 2], nums[start_index - 1]);

    for (int i = start_index; i < end_index; i++) {
      int current_max = max(second_back_max_money + nums[i], one_back_max_money);
      second_back_max_money = one_back_max_money;
      one_back_max_money = current_max;
    }

    return one_back_max_money;
  }
};
