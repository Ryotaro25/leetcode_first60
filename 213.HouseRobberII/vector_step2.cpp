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

    int max_from_first = RobMoney(nums, 0, nums.size() - 1);
    int max_from_second = RobMoney(nums, 1, nums.size());

    return max(max_from_first, max_from_second);
  }

private:
  int RobMoney(const vector<int>& nums, int start, int end) {
    vector<int> max_money_so_far(end);
    max_money_so_far[start] = nums[start];
    max_money_so_far[start + 1] = max(nums[start], nums[start + 1]);

    for (int i = start + 2; i < end; i++) {
      max_money_so_far[i] = max(max_money_so_far[i - 2] + nums[i], max_money_so_far[i - 1]);
    }
    cout << max_money_so_far.back() << endl;
    return max_money_so_far.back();
  }
};
