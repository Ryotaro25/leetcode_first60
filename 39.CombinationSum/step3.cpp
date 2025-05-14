class Solution {
  public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<vector<int>> all_combinations;
      vector<int> partial_combination;
      sort(candidates.begin(), candidates.end());
      GenerateCombinationToTarget(all_combinations, partial_combination, candidates, target, 0);
      return all_combinations;
    }
  
  private:
    void GenerateCombinationToTarget(vector<vector<int>>& all_combinations, vector<int>& partial_combination,
                                     const vector<int>& candidates, int remain, int start) {
      if (remain == 0) {
        all_combinations.push_back(partial_combination);
        return;
      }
      for (int i = start; i < candidates.size(); i++) {
        if (candidates[i] > remain) {
          break;
        }
        partial_combination.push_back(candidates[i]);
        GenerateCombinationToTarget(all_combinations, partial_combination, candidates, remain - candidates[i], i);
        partial_combination.pop_back();
      }
    }
  };
