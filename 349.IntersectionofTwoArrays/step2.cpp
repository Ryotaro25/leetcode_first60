class Solution {
public:
    vector<int> intersection(vector<int>& number1, vector<int>& number2) {
        set<int> unique_number1;
        for (auto num : number1) {
            unique_number1.insert(num);
        }

        vector<int> intersection;
        for (auto num : number2) {
            if (unique_number1.contains(num)) {
                intersection.push_back(num);
                unique_number1.erase(num);
            }
        }

        return intersection;
    }
};
