class Solution {
  public:
    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> permutations;
      vector<int> partial_permutation;
      set<int> notused(nums.begin(), nums.end());
      GeneratePermutation(nums, permutations, partial_permutation, notused);
      return permutations;
    }

  private:
    void GeneratePermutation(const vector<int>& nums, vector<vector<int>>& permutations,
                             vector<int>& partial_permutation, set<int>& notused) {
      if (partial_permutation.size() == nums.size()) {
        permutations.emplace_back(partial_permutation);
        return;
      }

      for (int num : nums) {
        if (!notused.contains(num)) {
          continue;
        }
        notused.erase(num);
        partial_permutation.push_back(num);
        GeneratePermutation(nums, permutations, partial_permutation, notused);
        partial_permutation.pop_back();
        notused.insert(num);
      }
    }
  };
