class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    vector<int> memoization(nums.size(), 1);

    int max_length = 0;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = 0; j < i; j++) {
        if (nums[i] > nums[j]) {
          memoization[i] = max(memoization[i], memoization[j] + 1);
        }
      }
      max_length = max(max_length, memoization[i]);
    }

    return max_length;
  }
};
