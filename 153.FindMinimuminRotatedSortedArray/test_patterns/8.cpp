class Solution {
public:
  int findMin(vector<int>& nums) {
    int left = 0;
    int right = nums.size();

    while (left < right) {
      int middle = left + (right - left) / 2;
      cout << " LEFT : " << left << " MID : " << middle << " RIGHT : " << right << endl;
      cout << " " << endl;

      if (nums[middle] < nums.back()) {
        right = middle;
      } else {
        left = middle + 1;
      }
    }
    return nums[left];
  }
};
