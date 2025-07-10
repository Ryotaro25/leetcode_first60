class Solution {
  public:
    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> permutations;

      stack<vector<int>> partial_permutations;
      // 組み合わせを樹形図とみなして、全パターンの最上部使って初期化
      for (int num : nums) {
        partial_permutations.push({num});
      }

      while (!partial_permutations.empty()) {
        vector<int> current_nums = partial_permutations.top();
        partial_permutations.pop();

        if (current_nums.size() == nums.size()) {
          permutations.push_back(current_nums);
          continue;
        }

        for (int num : nums) {
          if (find(current_nums.begin(), current_nums.end(), num) == current_nums.end()) {
            vector<int> cloned = current_nums;  // コピーを作る
            cloned.push_back(num);
            partial_permutations.push(cloned);
          }
        }
      }

      return permutations;
    }
  };
