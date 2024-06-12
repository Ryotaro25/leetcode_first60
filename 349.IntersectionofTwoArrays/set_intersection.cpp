class Solution {
public:
    vector<int> intersection(vector<int>& number1, vector<int>& number2) {
        set<int> unique_number1;
        for (auto i : number1) {
            unique_number1.insert(i);
        }
        set<int> unique_number2;
        for (auto i : number2) {
            unique_number2.insert(i);
        }
        vector<int> intersection;
        set_intersection(unique_number1.begin(), unique_number1.end(), unique_number2.begin(), unique_number2.end(), back_inserter(intersection));
        return intersection;
    }
};
