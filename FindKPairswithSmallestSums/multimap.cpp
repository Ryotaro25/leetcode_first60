class Solution {
public:
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    multimap<int, nums> sum_and_nums;
    for (int i = 0; i < nums1.size(); i++) {
      for (int j = 0; j < nums2.size(); j++) {
        int sum = nums1[i] + nums2[j];
        if (sum_and_nums.size() < k) {
          sum_and_nums.insert({sum, {nums1[i], nums2[j]}});
          continue;
        }
        if (sum < sum_and_nums.rbegin()->first) {
          // erase can not take rbegin() or rend()
          // end() points the end of the container so *end() is undefined
          sum_and_nums.erase(prev(sum_and_nums.end()));
          sum_and_nums.insert({sum, {nums1[i], nums2[j]}});
          continue;
        }
        break;
      }
    }

    vector<vector<int>> k_smallest_pairs;
    for (auto [sum, nums] : sum_and_nums) {
      auto [num1, num2] = nums;
      k_smallest_pairs.push_back({num1, num2});
    }

    return k_smallest_pairs;
  }

private:
  struct nums {
    int nums1;
    int nums2;
  };
};
