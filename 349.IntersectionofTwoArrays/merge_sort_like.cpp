class Solution {
public:
    vector<int> intersection(vector<int>& number1, vector<int>& number2) {
        sort(number1.begin(), number1.end());
        sort(number2.begin(), number2.end());

        int i = 0;
        int j = 0;
        int current_numbebr = -1;
        vector<int> intersection;
        while (i < number1.size() && j < number2.size()) {
            if ((number1[i] == number2[j]) && number1[i] != current_numbebr) {
                intersection.push_back(number1[i]);
                current_numbebr = number1[i];
                i++;
                j++;
            } else if(number1[i] < number2[j]) {
                i++;
            } else if(number1[i] > number2[j]) {
                j++;
            } else {
                i++;
                j++;
            }
        }
        return intersection;
    }
};
