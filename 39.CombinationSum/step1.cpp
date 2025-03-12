class Solution {
  public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<vector<int>> all_candidates;
      vector<int> partial_candidate;
      GenerateCombinationToTarget(all_candidates, partial_candidate, candidates, target, 0, 0);
      return all_candidates;
    }
  
  private:
    void GenerateCombinationToTarget(vector<vector<int>>& all_candidates, vector<int>& partial_candidate,
                                     const vector<int>& candidates, int target, int start, int sum) {
      if (sum == target) {
        all_candidates.push_back(partial_candidate);
        return;
      }
      if (sum > target) {
        return;
      }
      for (int i = start; i < candidates.size(); i++) {
        partial_candidate.push_back(candidates[i]);
        int partial_sum = 0;
        for (int num : partial_candidate) {
          partial_sum += num;
        }
        GenerateCombinationToTarget(all_candidates, partial_candidate, candidates, target, i, partial_sum);
        partial_candidate.pop_back();
      }
    }
  };
