class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        multimap<int, pair<int, int>> sums;

        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                int sum = nums1[i] + nums2[j];
                if (sums.size() < k) {
                    sums.insert({sum, {nums1[i], nums2[j]}});
                } else if (sum < sums.rbegin()->first) {
                    sums.erase(prev(sums.end()));
                    sums.insert({sum, {nums1[i], nums2[j]}});
                } else {
                    break;
                }
            }
        }

        vector<vector<int>> smallest_pairs_to_sum(k);
        smallest_pairs_to_sum.clear();
        int i = 0;
        for (auto [sum, values] : sums) {
            auto [number1, number2] = values;
            smallest_pairs_to_sum.push_back({number1, number2});
            i++;
            if (i >= k) {
                break;
            }
        }

        return smallest_pairs_to_sum;
    }
};
