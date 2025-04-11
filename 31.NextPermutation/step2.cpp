class Solution {
  public:
    void nextPermutation(vector<int>& nums) {
      int pivot_index = nums.size() - 1;

      // numsを後ろから探索して昇順となっている箇所をpivotとする
      while (pivot_index > 0 && nums[pivot_index - 1] >= nums[pivot_index]) {
        pivot_index--;
      }

      // 先頭から見てnums全てが降順に並んでいる場合は対象外
      // pivot_index - 1より大きく、最も右側の位置に存在している値を探して
      // pivot_index - 1と入れ替える
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
