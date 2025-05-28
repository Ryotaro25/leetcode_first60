class Solution {
public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.empty() || nums2.empty()) {
      return {};
    }
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    int index1 = 0;
    int index2 = 0;
    vector<int> intersection;
    while (index1 < nums1.size() && index2 < nums2.size()) {
      if (nums1[index1] == nums2[index2]) {
        if (intersection.empty() || intersection.back() != nums1[index1]) {
          intersection.push_back(nums1[index1]);
        }
        index1++;
        index2++;
        continue;
      }

      if (nums1[index1] < nums2[index2]) {
        index1++;
      } else {
        index2++;
      }
    }
    return intersection;
  }
};
