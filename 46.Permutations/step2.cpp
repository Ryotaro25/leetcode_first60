class Solution {
  public:
    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> permutations;
      vector<int> partial_permutations;
      GeneratePermutation(permutations, partial_permutations, nums);
      return permutations;
    }

  private:
    void GeneratePermutation(vector<vector<int>>& permutations,
                                   vector<int>& partial_permutations,
                                   const vector<int>& nums) {
      if (partial_permutations.size() == nums.size()) {
        permutations.push_back(partial_permutations);
        return;
      }

      for (int num : nums) {
        if (find(partial_permutations.begin(), partial_permutations.end(), num) != partial_permutations.end()) {
          continue;
        }
        partial_permutations.push_back(num);
        GeneratePermutation(permutations, partial_permutations, nums);
        partial_permutations.pop_back();
      }
    }
  };
