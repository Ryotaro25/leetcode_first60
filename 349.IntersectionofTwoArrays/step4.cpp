class Solution {
public:
    vector<int> intersection(vector<int>& number1, vector<int>& number2) {
        set<int> unique_number1(number1.begin(), number1.end());
        set<int> unique_number2(number2.begin(), number2.end());

        vector<int> intersection;
        set_intersection(unique_number1.begin(), unique_number1.end(), unique_number2.begin(), unique_number2.end(), back_inserter(intersection));
        return intersection;
    }
};
