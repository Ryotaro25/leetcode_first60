class Solution {
  public:
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int>> all_subsets;
      vector<int> partial_subset = {};
      GenerateSubset(all_subsets, partial_subset, 0, nums);
      return all_subsets;
    }

  private:
    void GenerateSubset(vector<vector<int>>& all_subsets, vector<int>& partial_subset,
                        int start, const vector<int>& nums) {
      all_subsets.push_back(partial_subset);

      for (int i = start; i < nums.size(); i++) {
        partial_subset.push_back(nums[i]);
        GenerateSubset(all_subsets, partial_subset, i + 1, nums);
        partial_subset.pop_back();
      }
    }
  };
