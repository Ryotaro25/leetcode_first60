class Solution {
public:
  int findMin(vector<int>& nums) {
    int left = 0;
    int right = nums.size();

    while (left < right) {
      // 切り上げ
      int middle = left + (right - left + 1) / 2;
      // nums = [4,5,6,7,0,1,2]
      // 1巡目left = 0, right = 7 middle = 4
      // 2巡目left = 0, right = 4 middle = 2
      // 3巡目left = 3, right = 4 middle = 4
      // 4巡目left = 3, right = 4 middle = 4
      // 5巡目left = 3, right = 4 middle = 4

      if (nums[middle] < nums.back()) {
        right = middle;
      } else {
        left = middle + 1;
      }
    }
    return nums[left];
  }
};
