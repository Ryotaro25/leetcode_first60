class Solution {
public:
  int findMin(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;
    
    int min_num = std::numeric_limits<int>::max();

    while (left <= right) {
      int middle = (left + right) / 2;
      min_num = min(min_num, nums[middle]);

      if (nums[middle] <= nums[right]) {
        right = middle - 1;
      } else {
        left = middle + 1;
      }
    }

    return min_num;
  }
};
