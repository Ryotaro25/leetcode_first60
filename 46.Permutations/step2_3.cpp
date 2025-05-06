class Solution {
  public:
    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> permutations;
      vector<int> partial_permutations;
      // 重複管理用
      vector<bool> used(nums.size(), false);
      GeneratePermutation(permutations, partial_permutations, nums, used);
      return permutations;
    }

  private:
    void GeneratePermutation(vector<vector<int>>& permutations,
                                   vector<int>& partial_permutations,
                                   const vector<int>& nums,
                                   vector<bool>& used
                                  ) {
      if (partial_permutations.size() == nums.size()) {
        permutations.push_back(partial_permutations);
        return;
      }

      for (int i = 0; i < nums.size(); i++) {
        // 既に使われている組みわせ
        if (used[i]) {
          continue;
        }
        // 同じ値が連続して現れる場合、前の同じ要素がまだ使われていなければスキップする
        // 順列を生成する中で、ある数字を選んでその順列に加えた後、
        // 次にその数字をもう一度選ぼうとすると同じ順列が再度生成される
        if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
          continue;
        }
        used[i] = true;
        partial_permutations.push_back(nums[i]);
        GeneratePermutation(permutations, partial_permutations, nums, used);
        partial_permutations.pop_back();
        used[i] = false;
      }
    }
  };
