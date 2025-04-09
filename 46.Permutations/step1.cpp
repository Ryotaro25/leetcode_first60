class Solution {
  public:
    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> permuted_combination;
      vector<int> current_nums;
      CreatePermutedCombination(permuted_combination, current_nums, nums);
      return permuted_combination;
    }

  private:
    void CreatePermutedCombination(vector<vector<int>>& permuted_combination,
                                   vector<int>& current_nums,
                                   const vector<int>& nums) {
      if (current_nums.size() == nums.size()) {
        permuted_combination.push_back(current_nums);
        return;
      }

      for (int num : nums) {
        if (find(current_nums.begin(), current_nums.end(), num) == current_nums.end()) {
          current_nums.push_back(num);
          CreatePermutedCombination(permuted_combination, current_nums, nums);
          current_nums.pop_back();
        }
      }
    }
  };
