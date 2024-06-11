class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        multimap<int, pair<int, int>> sums_and_pairs;

        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                int sum = nums1[i] + nums2[j];
                if (sums_and_pairs.size() < k) {
                    sums_and_pairs.insert({sum, {nums1[i], nums2[j]}});
                } else if (sum < sums_and_pairs.rbegin()->first) {
                    sums_and_pairs.erase(prev(sums_and_pairs.end()));
                    sums_and_pairs.insert({sum, {nums1[i], nums2[j]}});
                } else {
                    break;
                }
            }
        }

        vector<vector<int>> smallest_pairs(k);
        smallest_pairs.clear();
        for (auto [sum, values] : sums_and_pairs) {
            auto [number1, number2] = values;
            smallest_pairs.push_back({number1, number2});
        }

        return smallest_pairs;
    }
};
