class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    return SearchInsertIndex(0, nums.size(), nums, target);
  }

private:
  int SearchInsertIndex(int start, int end, vector<int>& nums, int target) {
    if (start >= end) {
      return start;
    }
    int middle = start + (end - start) / 2;

    // 右側を狭める場合
    if (nums[middle] < target) {
      return SearchInsertIndex(middle + 1, end, nums, target);
    } else {
      return SearchInsertIndex(start, middle, nums, target);
    }
  }
};
