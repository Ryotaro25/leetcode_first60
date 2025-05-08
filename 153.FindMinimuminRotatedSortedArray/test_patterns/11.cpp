class Solution {
public:
  int findMin(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
      // 切り上げ
      int middle = left + (right - left + 1) / 2;
      // [3,4,5,1,2]
      cout << middle << endl;

      if (nums[middle] <= nums.back()) {
        right = middle;
      } else {
        left = middle + 1;
      }
    }
    return nums[left];
  }
};
