class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> unique_number1;
        for (auto num : nums1) {
            unique_number1.insert(num);
        }

        vector<int> intersection;
        for (auto num : nums2) {
            if (unique_number1.contains(num)) {
                intersection.push_back(num);
                unique_number1.erase(num);
            }
        }

        return intersection;
    }
};
