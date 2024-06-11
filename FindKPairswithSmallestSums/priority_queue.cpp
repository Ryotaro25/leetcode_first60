class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, pair<int, int>>> sums_and_pairs;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j< nums2.size(); j++) {
                int sum = nums1[i] + nums2[j];

                if (sums_and_pairs.size() < k) {
                    sums_and_pairs.push({sum, {nums1[i], nums2[j]}});
                } else if (sum < sums_and_pairs.top().first) {
                    sums_and_pairs.pop();
                    sums_and_pairs.push({sum, {nums1[i], nums2[j]}});
                } else {
                    break;
                }
            }
        }

        vector<vector<int>> smallest_pairs;
        while (!empty(sums_and_pairs)) {
            int number1 = sums_and_pairs.top().second.first;
            int number2 = sums_and_pairs.top().second.second;
            smallest_pairs.push_back({number1, number2});

            sums_and_pairs.pop();
        }

        return smallest_pairs;
    }
};
