class Solution {
  public:
    void nextPermutation(vector<int>& nums) {
      int left = FindDecreasingIndex(nums);
      // nums全体が降順になっている場合
      if (left == -1) {
        reverse(nums.begin(), nums.end());
        return;
      }
      int right = FindRightmostLarger(nums, left);
      swap(nums[left], nums[right]);
      reverse(nums.begin() + left + 1, nums.end());
    }

private:
  // 右側が降順になっている範囲の直前のインデックスを探す
  int FindDecreasingIndex(const vector<int>& nums) {
    int index = nums.size() - 2;
    while (index >= 0 && nums[index] >= nums[index + 1]) {
      index--;
    }
    return index;
  }

  // 大きい値のうち、最も右側のものを見つける
  int FindRightmostLarger(vector<int>& nums, int left) {
    auto it = lower_bound(nums.begin() + left + 1, nums.end(), nums[left], greater<int>());
    return distance(nums.begin(), it) - 1;
  }
};
