class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    return SearchInsertIndex(0, nums.size() - 1, nums, target);
  }

private:
  int SearchInsertIndex(int start, int end, vector<int>& nums, int target) {
    if (start > end) {
      return start;
    }
    int middle = (start + end) / 2;
    if (nums[middle] == target) {
      return middle;
    }

    if (nums[middle] < target) {
      return SearchInsertIndex(middle + 1, end, nums, target);
    } else {
      return SearchInsertIndex(start, middle - 1, nums, target);
    }
  }
};
