class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    set<int> unique_nums;
    for (auto num : nums) {
      if (unique_nums.contains(num)) {
        return true;
      }
      unique_nums.insert(num);
    }
    return false;
  }
};
