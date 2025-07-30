class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    set<vector<int>> unique_triplets;
    set<int> used_first_nums;
    for (int i = 0; i < nums.size(); i++) {
      if (used_first_nums.contains(nums[i])) {
        continue;
      }
      used_first_nums.insert(nums[i]);

      set<int> seen;
      for (int j = i + 1; j < nums.size(); j++) {
        int complement = -nums[i] - nums[j];
        if (!seen.contains(complement)) {
          seen.insert(nums[j]);
          continue;
        }

        vector<int> triplet = {nums[i], nums[j], complement};
        sort(triplet.begin(), triplet.end());
        unique_triplets.insert(triplet);
      }
    }

    return vector<vector<int>>(unique_triplets.begin(), unique_triplets.end());
  }
};
