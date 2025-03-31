class Solution {
  public:
    void nextPermutation(vector<int>& nums) {
      // 後ろから探索して、numsの中で最初に前から昇順に並んでいるインデックスを探す
      int first_increasing_order_index = 0;
      for (int i = nums.size() - 1; i > 0; i--) {
        if (nums[i - 1] < nums[i]) {
          first_increasing_order_index = i;
          break;
        }
      }

      if (first_increasing_order_index > 0) {
        // first_increasing_order_index より大きい値を持つ最も右の要素を探す
        for (int i = nums.size() - 1; i >= first_increasing_order_index; i--) {
          if (nums[i] > nums[first_increasing_order_index - 1]) {
            swap(nums[first_increasing_order_index - 1], nums[i]);
            break;
          }
        }
      }

      reverse(nums.begin() + first_increasing_order_index, nums.end());
    }
  };
