class Solution {
  public:
    void nextPermutation(vector<int>& nums) {
      int first_increasing_order_index = nums.size() - 1;
      while (first_increasing_order_index > 0) {
        if (nums[first_increasing_order_index - 1] < nums[first_increasing_order_index]) {
          break;
        }
        first_increasing_order_index--;
      }

      if (first_increasing_order_index > 0) {
        int next_larger_index = nums.size() - 1;
        while (nums[next_larger_index] <= nums[first_increasing_order_index - 1]) {
          next_larger_index--;
        }
        swap(nums[first_increasing_order_index - 1], nums[next_larger_index]);
      }

      reverse(nums.begin() + first_increasing_order_index, nums.end());
    }
  };
