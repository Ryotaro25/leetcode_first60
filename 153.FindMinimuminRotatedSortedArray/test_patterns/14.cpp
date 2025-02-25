class Solution {
public:
  int findMin(vector<int>& nums) {
    int left = 0;
    int right = nums.size();

    while (left < right) {
      // 切り上げ
      int middle = left + (right - left + 1) / 2;

      if (nums[middle] < nums[right]) {
        right = middle;
      } else {
        left = middle + 1;
      }
    }
    return nums[left];
  }
};
