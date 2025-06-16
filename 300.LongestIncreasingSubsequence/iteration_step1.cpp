class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }
    vector<int> increasing_nums;
    increasing_nums.push_back(nums[0]);
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] > increasing_nums.back()) {
        increasing_nums.push_back(nums[i]);
        continue;
      }
      // find first larger or equal num
      int greater_or_equal_index = 0;
      while (nums[i] > increasing_nums[greater_or_equal_index]) {
        greater_or_equal_index++;
      }
      increasing_nums[greater_or_equal_index] = nums[i];
    }

    return increasing_nums.size();
  }
};
