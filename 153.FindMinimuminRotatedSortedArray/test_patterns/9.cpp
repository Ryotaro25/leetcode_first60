class Solution {
public:
  int findMin(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
      // 切り上げ
      int middle = left + (right - left + 1) / 2;
      // [3,4,5,1,2]
      // 1巡目left = 0, right = 4 middle = 2
      // 2巡目left = 3, right = 4 middle = 3
      // 3巡目left = 3, right = 4 middle = 3

      if (nums[middle] <= nums[right]) {
        right = middle;
      } else {
        left = middle + 1;
      }
    }
    return nums[left];
  }
};
