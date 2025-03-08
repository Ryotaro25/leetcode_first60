class Solution {
  public:
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int>> all_subsets;
      vector<int> partial_subset;
      all_subsets.push_back({});

      for (int i = 1; i <= nums.size(); i++) {
        GenerateSubset(all_subsets, partial_subset, nums, i, 0);
      }
      return all_subsets;
    }

  private:
    void GenerateSubset(vector<vector<int>>& all_subsets, vector<int>& partial_subset,
                        const vector<int>& nums, int subset_size, int start_index) {
      if (partial_subset.size() == subset_size) {
        all_subsets.push_back(partial_subset);
        return;
      }

      for (int i = start_index; i < nums.size(); i++) {
        if (find(partial_subset.begin(), partial_subset.end(), nums[i]) != partial_subset.end()) {
          continue;
        }
        partial_subset.push_back(nums[i]);
        GenerateSubset(all_subsets, partial_subset, nums,subset_size, i + 1);
        partial_subset.pop_back();
      }
    } 
  };
