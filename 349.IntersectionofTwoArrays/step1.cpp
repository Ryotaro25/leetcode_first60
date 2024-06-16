class Solution {
public:
    vector<int> intersection(vector<int>& number1, vector<int>& number2) {
        unordered_map<int, int> unique_number1;
        for (auto num : number1) {
            unique_number1[num] = num;
        }

        set<int> unique_numbers;
        for (auto num : number2) {
            if (unique_number1.contains(num)) {
                unique_numbers.insert(num);
            }
        }

        vector<int> intersection;
        for (auto num : unique_numbers) {
            intersection.push_back(num);
        }

        return intersection;
    }
};
