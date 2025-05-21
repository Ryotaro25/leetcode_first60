class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> frequency(26, 0);
        for (auto letter : s) {
            frequency[letter - 'a']++;
        }

        for (int i = 0; i < s.size(); i++) {
            if (frequency[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};
