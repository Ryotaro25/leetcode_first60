class Solution {
public:
  int UNDEFINED = -1;

  int rob(vector<int>& nums) {

    vector<int> max_money_so_far(nums.size(), UNDEFINED);
    return FindMaxRob(nums.size() - 1, nums, max_money_so_far);
  }

private:
  int FindMaxRob(int i, const vector<int> &nums, vector<int> &max_money_so_far) {
    if (i == 0) {
      return nums[0];
    }
    if (i == 1) {
      return max(nums[0], nums[1]);
    }

    if (max_money_so_far[i] != UNDEFINED) {
      return max_money_so_far[i];
    }

    max_money_so_far[i] = max(FindMaxRob(i - 1, nums, max_money_so_far), FindMaxRob(i - 2, nums, max_money_so_far) + nums[i]);

    return max_money_so_far[i];
  }
};
