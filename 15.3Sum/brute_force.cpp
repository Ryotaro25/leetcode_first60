class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    if (nums.empty()) {
      return {};
    }
    set<vector<int>> unique_triplets;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = 0; j < nums.size(); j++) {
        for (int k = 0; k < nums.size(); k++) {
          if (i == j || j == k || k == i) {
            continue;
          }
          if (nums[i] + nums[j] + nums[k] == 0) {
            vector<int> triplet = {nums[i], nums[j], nums[k]};
            sort(triplet.begin(), triplet.end());
            unique_triplets.insert(triplet);
          }
        }
      }
    }

    return vector<vector<int>>(unique_triplets.begin(), unique_triplets.end());
  }
};
