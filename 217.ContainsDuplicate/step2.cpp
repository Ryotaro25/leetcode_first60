class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    set<int> seen;
    for (auto num : nums) {
      if (seen.contains(num)) {
        return true;
      }
      seen.insert(num);
    }
    return false;
  }
};
