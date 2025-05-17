class Solution {
  public:
    void moveZeroes(vector<int>& nums) {
      int non_zero_index = 0;
      for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
          swap(nums[non_zero_index], nums[i]);
          non_zero_index++;
        }
      }
    }
  };
