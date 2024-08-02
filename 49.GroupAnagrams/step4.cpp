class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> sorted_to_group;
        for (auto& str : strs) {
            string anagram = str;
            sort(anagram.begin(), anagram.end());
            sorted_to_group[anagram].push_back(move(str));
        }

        vector<vector<string>> group_anagrams;
        for (auto& [key, word_group] : sorted_to_group) {
            group_anagrams.push_back(move(word_group));
        }

        return group_anagrams;
    }
};
