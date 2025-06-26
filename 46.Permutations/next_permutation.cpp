class Solution {
  public:
    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> permutations;
      sort(nums.begin(), nums.end());
      permutations.push_back(nums);

      while (next_permutation(nums.begin(), nums.end())) {
        permutations.push_back(nums);
      }
      return permutations;
    }
  };
