class Solution {
public:
    vector<int> intersection(vector<int>& number1, vector<int>& number2) {
        sort(number1.begin(), number1.end());
        sort(number2.begin(), number2.end());

        int i = 0;
        int j = 0;
        vector<int> intersection;
        while (i < number1.size() && j < number2.size()) {
            if (number1[i] == number2[j]) {
                intersection.push_back(move(number1[i]));
                int current_number = number1[i];
                while (i < number1.size() &&
                       j < number2.size() &&
                       current_number == number1[i] &&
                       number1[i] == number2[j]) {
                    i++;
                    j++;
                }
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
