class Solution {
  public:
    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> permutations;
      vector<int> indices(nums.size());
      // 初期のインデックス [0, 1, 2, ..., n-1]
      iota(indices.begin(), indices.end(), 0);
      vector<int> cycles(nums.size());
      for (int i = 0; i < nums.size(); ++i) {
        cycles[i] = nums.size() - i;
      }

      while (true) {
        // 現在の順列を保存
        permutations.push_back(generatePermutation(nums, indices));
        // 次の順列の準備
        bool done = true;
        for (int i = nums.size() - 1; i >= 0; i--) {
          cycles[i]--;
          if (cycles[i] == 0) {
            // 最後まで来た場合、インデックスを移動
            rotate(indices.begin() + i, indices.begin() + i + 1, indices.end());
            cycles[i] = nums.size() - i;
          } else {
            // 順列を交換
            swap(indices[i], indices[nums.size() - cycles[i]]);
            done = false;
            break;
          }
        }

        if (done) {
          break;
        }
      }
      return permutations;
    }
  
  private:
    vector<int> generatePermutation(const vector<int>& nums, const vector<int>& indices) {
      vector<int> permuted;
      for (int index : indices) {
        permuted.push_back(nums[index]);
      }
      return permuted;
    }
  };
