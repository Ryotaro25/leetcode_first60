class Solution {
public:
  int search(vector<int>& nums, int target) {
    int left = 0;
    // rightの外側は不要
    int right = nums.size() - 1;
    int min_index = FindMinIndex(nums);

    if (nums[min_index] <= target && target <= nums[right]) {
      left = min_index;
    } else {
      right = min_index - 1;
    }

    return BinarySearch(nums, left, right, target);
  }

private:
  int FindMinIndex(const vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
      int middle = (left + right) / 2;
      if (nums[middle] <= nums[right]) {
        right = middle;
      } else {
        left = middle + 1;
      }
    }

    return left;
  }

  int BinarySearch(const vector<int>& nums, int left, int right, int target) {
    // right自身もtargetとなる可能性がある
    while (left <= right) {
      int middle = (left + right) / 2;
      if (nums[middle] == target) {
        return middle;
      }

      // middleは除外する
      if (nums[middle] < target) {
        left = middle + 1;
      } else {
        right = middle - 1;
      }
    }

    return -1;
  }
};
