class Solution {
  public:
    void nextPermutation(vector<int>& nums) {
      int pivot_index = nums.size() - 1;
      while (pivot_index > 0 && nums[pivot_index - 1] >= nums[pivot_index]) {
        pivot_index--;
      }

      if (pivot_index > 0) {
        int rightmost_larger_index = nums.size() - 1;
        while (nums[rightmost_larger_index] <= nums[pivot_index - 1]) {
          rightmost_larger_index--;
        }
        swap(nums[pivot_index - 1], nums[rightmost_larger_index]);
      }

      sort(nums.begin() + pivot_index, nums.end());
    }
  };
