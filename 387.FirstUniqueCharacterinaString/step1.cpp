class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> letter_to_count;
        for (auto letter : s) {
            letter_to_count[letter]++;
        }

        for (int i = 0; i < s.size(); i++) {
            if (letter_to_count[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};
