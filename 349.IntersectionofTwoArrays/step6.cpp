class Solution {
public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.empty() || nums2.empty()) {
      return {};
    }

    set<int> unique_nums1(nums1.begin(), nums1.end());
    set<int> unique_nums2(nums2.begin(), nums2.end());
    vector<int> intersection;
    for (int num : unique_nums2) {
      if (unique_nums1.contains(num)) {
        intersection.push_back(num);
      }
    }
    return intersection;
  }
};
