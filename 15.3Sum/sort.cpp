class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> triplets;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > 0) {
        break;
      }
      if (i == 0) {
        FindTriplet(nums, i, triplets);
        continue;
      }
      if (nums[i] != nums[i - 1]) {
        FindTriplet(nums, i, triplets);
      }
    }
    return triplets;
  }

private:
  void FindTriplet(vector<int>& nums, int index, vector<vector<int>>& triplets) {
    int left = index + 1;
    int right = nums.size() - 1;
    while (left < right) {
      int sum = nums[index] + nums[left] + nums[right];
      if (sum < 0) {
        left++;
      } else if (sum > 0) {
        right--;
      } else {
        triplets.push_back({nums[index], nums[left], nums[right]});
        left++;
        while (left < right && nums[left] == nums[left - 1]) {
          left++;
        }
        right--;
        while (left < right && nums[right] == nums[right + 1]) {
          right--;
        }
      }
    }
  }
};
