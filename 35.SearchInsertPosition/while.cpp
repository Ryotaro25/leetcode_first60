class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    int start = 0;
    int end = nums.size();

    while (start < end) {
      int middle = (start + end) / 2;

      if (nums[middle] == target) {
        return middle;
      }
      if (nums[middle] < target) {
        start++;
      }
      if (nums[middle] > target) {
        end = middle;
      }
    }

    return end;
  }
};
