class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    if (nums.empty()) {
      return {};
    }

    map<int, int> num_to_index;
    for (int i = 0; i < nums.size(); i++) {
      int remain = target - nums[i];
      if (num_to_index.contains(remain)) {
        return {num_to_index[remain], i};
      }
      num_to_index[nums[i]] = i;
    }
    return {};
  }
};
