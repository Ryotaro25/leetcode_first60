class Solution {
  public:
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int>> all_subsets;
      all_subsets.push_back({});

      for (int num : nums) {
        vector<vector<int>> partial_subset;
        for (auto prev_subset : all_subsets) {
          // 一つ前の状態を取り出して、部分集合(現在のnum)を追加する
          vector<int> cloned = prev_subset;
          cloned.push_back(num);
          partial_subset.push_back(cloned);
        }
        // この周回で作った集合を次の周回に渡すための処理
        for (auto subset : partial_subset) {
          all_subsets.push_back(subset);
        }
      }
      return all_subsets;
    }
  };
