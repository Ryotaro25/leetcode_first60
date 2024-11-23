class Solution {
public:
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    priority_queue<SumAndNums> sum_and_nums;
    for (int i = 0; i < nums1.size(); i++) {
      for (int j = 0; j < nums2.size(); j++) {
        int sum = nums1[i] + nums2[j];
        if (sum_and_nums.size() < k) {
          sum_and_nums.push({sum, nums1[i], nums2[j]});
          continue;
        }

        if (sum < sum_and_nums.top().sum) {
          sum_and_nums.pop();
          sum_and_nums.push({sum, nums1[i], nums2[j]});
          continue;
        }
        break;
      }
    }

    vector<vector<int>> k_smallest_pairs;
    while (!sum_and_nums.empty()) {
      k_smallest_pairs.push_back({sum_and_nums.top().num1, sum_and_nums.top().num2});
      sum_and_nums.pop();
    }

    return k_smallest_pairs;
  }

private:
  struct SumAndNums {
    int sum;
    int num1;
    int num2;
   
    // instead using pair, the comparision operator should be needed
    bool operator<(const SumAndNums& other) const {
      return sum < other.sum;
    }
  };
};
