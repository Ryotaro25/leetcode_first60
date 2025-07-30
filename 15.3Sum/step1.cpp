class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    set<vector<int>> unique_triplets;
    // 3組の内ひとつ目の数字をユニークにするために使用
    set<int> first_nums;
    for (int i = 0; i < nums.size(); i++) {
      if (first_nums.contains(nums[i])) {
        continue;
      }
      first_nums.insert(nums[i]);

      // nums[i]に対応する(nums[j], complement)のペアを探すために
      // 既にnums[j]として通りすぎた数字を記録する。
      set<int> seen;
      for (int j = i + 1; j < nums.size(); j++) {
        int complement = -nums[i] - nums[j];
        if (!seen.contains(complement)) {
          seen.insert(nums[j]);
          continue;
        }

        vector<int> triplet = {nums[i], nums[j], complement};
        sort(triplet.begin(), triplet.end());
        unique_triplets.insert(triplet);
      }
    }

    // vectorに変換して返す
    return vector<vector<int>>(unique_triplets.begin(), unique_triplets.end());
  }
};
