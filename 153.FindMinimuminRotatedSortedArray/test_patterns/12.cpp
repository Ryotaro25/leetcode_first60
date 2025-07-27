class Solution {
public:
  int findMin(vector<int>& nums) {
    int left = 0;
    int right = nums.size();

    while (left < right) {
      // 切り上げ
      int middle = left + (right - left + 1) / 2;
      // [3,4,5,1,2]
      // 1巡目left = 0, right = 5 middle = 3
      // 2巡目left = 0, right = 3 middle = 2
      // 3巡目left = 3, right = 3 middle = 3
      // 4巡目left = 3, right = 3 middle = 3

      if (nums[middle] <= nums.back()) {
        right = middle;
      } else {
        left = middle + 1;
      }
    }
    return nums[left];
  }
};
