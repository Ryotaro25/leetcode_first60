class Solution {
  public:
    void moveZeroes(vector<int>& nums) {
      int last_zero_index = 0;
      for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {
          continue;
        }
        nums[last_zero_index] = nums[i];
        last_zero_index++;
      }

      for (int i = last_zero_index; i < nums.size(); i++) {
        nums[i] = 0;
      }
    }
  };
