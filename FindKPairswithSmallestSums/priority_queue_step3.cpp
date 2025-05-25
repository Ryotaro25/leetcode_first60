class Solution {
public:
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    if (nums1.empty() || nums2.empty()) {
      return {};
    }

    priority_queue<SumAndPair> sums_and_pairs;
    for (int i = 0; i < nums1.size(); i++) {
      for (int j = 0; j < nums2.size(); j++) {
        int sum = nums1[i] + nums2[j];
        if (sums_and_pairs.size() < k) {
          sums_and_pairs.push({sum, nums1[i], nums2[j]});
          continue;
        }
        if (sum < sums_and_pairs.top().sum) {
          sums_and_pairs.pop();
          sums_and_pairs.push({sum, nums1[i], nums2[j]});
          continue;
        }
        break;
      }
    }

    vector<vector<int>> k_smallest_pairs;
    while (!sums_and_pairs.empty()) {
      auto sum_and_pair = sums_and_pairs.top();
      sums_and_pairs.pop();
      k_smallest_pairs.push_back({sum_and_pair.num1, sum_and_pair.num2});
    }
    return k_smallest_pairs;
  }

struct SumAndPair {
  int sum;
  int num1;
  int num2;

  bool operator<(const SumAndPair& other) const {
    return sum < other.sum;
  }
};
};
