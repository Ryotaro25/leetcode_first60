class Solution {
public:
  int findMin(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
      // 切り上げ
      int middle = left + (right - left + 1) / 2;
      cout << left << endl;
      // nums = [4,5,6,7,0,1,2]
      // 1巡目left = 0, right = 6 middle = 3
      // 2巡目left = 4, right = 6 middle = 5
      // 3巡目left = 4, right = 5 middle = 5
      // 4巡目left = 4, right = 5 middle = 5

      if (nums[middle] < nums[right]) {
        right = middle;
      } else {
        left = middle + 1;
      }
    }
    return nums[left];
  }
};
