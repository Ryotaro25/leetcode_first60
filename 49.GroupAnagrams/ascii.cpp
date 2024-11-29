class Solution {
private:
    vector<int> count_alphabet(string s) {
            vector<int> counts(26, 0);
            for (char c : s) {
                counts[c - 'a']++;
            }
            return counts;
    };

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> sorted_to_group;
        for (auto str : strs) {
            vector<int> counts = count_alphabet(str);
            string key;
            // chatGPTにて確認
            for (int count : counts) {
                key += '#' + to_string(count);
            }
            sorted_to_group[key].push_back(str);
        }

        vector<vector<string>> group_anagrams;
        for (auto [key, word_group] : sorted_to_group) {
            group_anagrams.push_back(word_group);
        }

        return group_anagrams;
    }
};
