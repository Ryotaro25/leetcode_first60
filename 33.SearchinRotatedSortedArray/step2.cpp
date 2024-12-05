class Solution {
public:
  int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    // right自身がtargetの可能性あり
    while (left <= right) {
      int middle = (left + right) / 2;

      if (nums[middle] == target) {
        return middle;
      }

      // middleからrightまでは昇順に並んでいる
      if (nums[middle] < nums[right]) {
        // middleを含め左側にはtargetは存在しない
        if (nums[middle] < target && target <= nums[right]) {
          left = middle + 1;
        } else {
          right = middle - 1;
        }
      } else {
        // 左端からmiddleまでは並んでいる
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
