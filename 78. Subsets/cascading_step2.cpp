class Solution {
  public:
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int>> all_subsets;
      all_subsets.push_back({});

      for (int num : nums) {
        vector<vector<int>> partial_subset;
        for (const auto& prev_subset : all_subsets) {
          vector<int> cloned = prev_subset;
          cloned.push_back(num);
          partial_subset.emplace_back(cloned);
        }
        for (const auto& subset : partial_subset) {
          all_subsets.emplace_back(subset);
        }
      }
      return all_subsets;
    }
  };
