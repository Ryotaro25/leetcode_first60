class Solution {
public:
  int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
      int middle = (left + right) / 2;

      if (nums[middle] == target) {
        return middle;
      }

      if (nums[middle] < nums[right]) {
        if (nums[middle] < target && target <= nums[right]) {
          left = middle + 1;
        } else {
          right = middle - 1;
        }
      } else {
        if (nums[left] <= target && target < nums[middle]) {
          right = middle - 1;
        } else {
          left = middle + 1;
        }
      }
    }
    return -1;
  }
};
