class Solution {
  public:
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int>> all_subsets;
      vector<int> subset_including_num = {};
      GenerateSubset(nums, 0, subset_including_num, all_subsets);
      return all_subsets;
    }

  private:
    void GenerateSubset(const vector<int>& nums, int start, vector<int>& subset_including_num,
                        vector<vector<int>>& all_subsets
                        ) {
      all_subsets.emplace_back(subset_including_num);

      for (int i = start; i < nums.size(); i++) {
        subset_including_num.push_back(nums[i]);
        GenerateSubset(nums, i + 1, subset_including_num, all_subsets);
        subset_including_num.pop_back();
      }
    }
  };
