class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    vector<int> longest_lengths(nums.size(), 1);

    int max_length = 0;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = 0; j < i; j++) {
        if (nums[j] < nums[i]) {
          longest_lengths[i] = max(longest_lengths[i], longest_lengths[j] + 1);
        }
      }

      max_length = max(max_length, longest_lengths[i]);
    }

    return max_length;
  }
};
