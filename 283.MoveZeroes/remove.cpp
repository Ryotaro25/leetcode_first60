class Solution {
  public:
    void moveZeroes(vector<int>& nums) {
      // 0を削除してしまった後の最後のindex
      auto end_index = remove(nums.begin(), nums.end(), 0); 
      fill(end_index, nums.end(), 0);
    }
  };
