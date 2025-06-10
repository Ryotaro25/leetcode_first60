class Solution {
public:
  int rob(vector<int>& nums) {
    int nums_size = nums.size();
    if (nums_size == 1) {
      return nums[0];
    }
    if (nums_size == 2) {
      return max(nums[0], nums[1]);
    }

    return max(RobMaxMoney(nums, 0, nums_size - 1), RobMaxMoney(nums, 1, nums_size));
  }

private:
  int RobMaxMoney(const vector<int>& nums, int start_index, int end_index) {
    int second_previous_max_money = nums[start_index];
    int previous_max_money = max(nums[start_index], nums[start_index + 1]);

    for (int i = start_index + 2; i < end_index; i++) {
      int current_max = max(second_previous_max_money + nums[i], previous_max_money);
      second_previous_max_money = previous_max_money;
      previous_max_money = current_max;
    }

    return previous_max_money;
  }
};
