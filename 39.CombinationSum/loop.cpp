class Solution {
  public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<vector<int>> all_combinations;
      stack<CombinationAndTargetAndIndex> combination_state;

      combination_state.push({{}, target, 0});

      while (!combination_state.empty()) {
        auto [partial_combination, remain, start] = combination_state.top();
        combination_state.pop();

        if (remain == 0) {
          all_combinations.push_back(partial_combination);
          continue;
        }
        if (remain < 0) continue;
          for (int i = start; i < candidates.size(); i++) {
            vector<int> added_combination = partial_combination;
            added_combination.push_back(candidates[i]);
            combination_state.push({added_combination, remain - candidates[i], i});
          }
        }
      return all_combinations;
    }

  private:
    struct CombinationAndTargetAndIndex {
      vector<int> combination;
      int remain;
      int index;
    };
};
