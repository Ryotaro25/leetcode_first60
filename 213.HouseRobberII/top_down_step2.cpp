class Solution {
public:
  const int UNDEFINED = -1;
  int rob(vector<int>& nums) {
    int num_size = nums.size();
    if (num_size == 1) {
      return nums[0];
    }
    if (num_size == 2) {
      return max(nums[0], nums[1]);
    }
    vector<int> memo_max_money_from_1(num_size, UNDEFINED);
    vector<int> memo_max_money_from_2(num_size, UNDEFINED);

    return max(RobMaxMoney(num_size - 1, 1, nums, memo_max_money_from_1), 
               RobMaxMoney(num_size - 2, 0, nums, memo_max_money_from_2));
  }

private:
  int RobMaxMoney(int index, int start_index, const vector<int>& nums, vector<int>& max_money) {
    if (index < start_index) {
      return 0;
    }
    if (max_money[index] != UNDEFINED) {
      return max_money[index];
    }

    max_money[index] = max(RobMaxMoney(index - 2, start_index, nums, max_money) + nums[index],
                           RobMaxMoney(index - 1, start_index, nums, max_money));

    return max_money[index];
  }
};
